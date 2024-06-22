#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ð?nh nghia c?u trúc cho tam giác
struct Triangle {
    float a, b, c;  // Ba c?nh c?a tam giác
    float perimeter;  // Chu vi tam giác
    float area;  // Di?n tích tam giác
};

// Ð?nh nghia c?u trúc cho node c?a danh sách liên k?t
struct Node {
    struct Triangle triangle;
    struct Node* next;
};

// Hàm ki?m tra ba c?nh có t?o thành tam giác không
int isTriangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Hàm tính chu vi c?a tam giác
float calculatePerimeter(float a, float b, float c) {
    return a + b + c;
}

// Hàm tính di?n tích c?a tam giác b?ng công th?c Heron
float calculateArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Hàm t?o m?t node m?i trong danh sách liên k?t
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

// Hàm chèn m?t tam giác vào danh sách liên k?t
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

// Hàm in ra thông tin c?a các tam giác trong danh sách liên k?t
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

// Hàm main d? ch?y chuong trình
int main() {
    struct Node* head = NULL;
    float a, b, c;
    char choice;
    
    do {
        // Nh?p ba c?nh c?a tam giác t? ngu?i dùng
        printf("nhap cac canh cua tam giac (a, b, c): ");
        scanf("%f %f %f", &a, &b, &c);
        
        // Ki?m tra xem ba c?nh có t?o thành tam giác không
        if (isTriangle(a, b, c)) {
            // N?u t?o thành tam giác, thêm tam giác vào danh sách liên k?t
            insertTriangle(&head, a, b, c);
            printf("Da nhap thanh cong \n");
        } else {
            printf("cac canh nay khong tao thanh tam giac,vui long thu lai.\n");
        }
        
        // H?i ngu?i dùng có mu?n ti?p t?c nh?p tam giác khác không
        printf("Ban co muon nhap mot hinh tam giac khac khang? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    // In ra thông tin c?a các tam giác trong danh sách liên k?t
    printTriangles(head);
    
    // Gi?i phóng b? nh?
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

