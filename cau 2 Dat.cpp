#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int stt;        
    int chieurong;  
    int chieudai;   
    int cao;        
    int thetich;   
} HinhHop;


typedef struct Node {
    HinhHop data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(HinhHop data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, HinhHop data) {
    
    if (root == NULL) {
        return createNode(data);
    }

    
    if (data.thetich < root->data.thetich) {
        root->left = insert(root->left, data);
    } else if (data.thetich > root->data.thetich) {
        root->right = insert(root->right, data);
    }

    
    return root;
}


void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%-4d %-9d %-9d %-4d %-7d\n", root->data.stt, root->data.chieurong, root->data.chieudai, root->data.cao, root->data.thetich);
        inorder(root->right);
    }
}

int main() {
    int n;
    printf("Nhap so luong khoi hinh hop: ");
    scanf("%d", &n);

    Node* root = NULL;

  
    for (int i = 0; i < n; i++) {
        HinhHop hinhHop;
        hinhHop.stt = i + 1;
        printf("Nhap chieu rong, chieu dai va chieu cao cua hinh hop thu %d: ", i + 1);
        scanf("%d %d %d", &hinhHop.chieurong, &hinhHop.chieudai, &hinhHop.cao);
        hinhHop.thetich = hinhHop.chieurong * hinhHop.chieudai * hinhHop.cao;

       
        root = insert(root, hinhHop);
    }

  
    printf("\nSTT  Chieu rong Chieu dai Cao  The tich\n");
    printf("-----------------------------------------\n");
    inorder(root);

    return 0;
}

