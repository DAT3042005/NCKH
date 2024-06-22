#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �?nh nghia c?u tr�c cho tam gi�c
struct Triangle {
    float a, b, c;  // Ba c?nh c?a tam gi�c
    float perimeter;  // Chu vi tam gi�c
    float area;  // Di?n t�ch tam gi�c
};

// �?nh nghia c?u tr�c cho node c?a danh s�ch li�n k?t
struct Node {
    struct Triangle triangle;
    struct Node* next;
};

// H�m ki?m tra ba c?nh c� t?o th�nh tam gi�c kh�ng
int isTriangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// H�m t�nh chu vi c?a tam gi�c
float calculatePerimeter(float a, float b, float c) {
    return a + b + c;
}

// H�m t�nh di?n t�ch c?a tam gi�c b?ng c�ng th?c Heron
float calculateArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// H�m t?o m?t node m?i trong danh s�ch li�n k?t
struct Node* createNode(float a, float b, float c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    newNode->triangle.a = a;
    newNode->triangle.b = b;
    newNode->triangle.c = c;
    newNode->triangle.perimeter = calculatePerimeter(a, b, c);
    newNode->triangle.area = calculateArea(a, b, c);
    newNode->next = NULL;
    
    return newNode;
}

// H�m ch�n m?t tam gi�c v�o danh s�ch li�n k?t
void insertTriangle(struct Node** head, float a, float b, float c) {
    struct Node* newNode = createNode(a, b, c);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// H�m in ra th�ng tin c?a c�c tam gi�c trong danh s�ch li�n k?t
void printTriangles(struct Node* head) {
    printf("=== List of triangles ===\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("Triangle sides: %.2f, %.2f, %.2f\n", current->triangle.a, current->triangle.b, current->triangle.c);
        printf("Perimeter: %.2f\n", current->triangle.perimeter);
        printf("Area: %.2f\n", current->triangle.area);
        printf("-------------------------\n");
        current = current->next;
    }
}

// H�m main d? ch?y chuong tr�nh
int main() {
    struct Node* head = NULL;
    float a, b, c;
    char choice;
    
    do {
        // Nh?p ba c?nh c?a tam gi�c t? ngu?i d�ng
        printf("nhap cac canh cua tam giac (a, b, c): ");
        scanf("%f %f %f", &a, &b, &c);
        
        // Ki?m tra xem ba c?nh c� t?o th�nh tam gi�c kh�ng
        if (isTriangle(a, b, c)) {
            // N?u t?o th�nh tam gi�c, th�m tam gi�c v�o danh s�ch li�n k?t
            insertTriangle(&head, a, b, c);
            printf("Da nhap thanh cong \n");
        } else {
            printf("cac canh nay khong tao thanh tam giac,vui long thu lai.\n");
        }
        
        // H?i ngu?i d�ng c� mu?n ti?p t?c nh?p tam gi�c kh�c kh�ng
        printf("Ban co muon nhap mot hinh tam giac khac khang? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    // In ra th�ng tin c?a c�c tam gi�c trong danh s�ch li�n k?t
    printTriangles(head);
    
    // Gi?i ph�ng b? nh?
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

