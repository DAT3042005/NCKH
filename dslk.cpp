#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh nghia c?u tr�c SinhVien
struct SinhVien {
    char ma_so[20];
    char ho_ten[50];
    int tuoi;
    struct SinhVien *next;
};

// H�m d? t?o m?t n�t m?i
struct SinhVien* tao_sinh_vien(char ma_so[], char ho_ten[], int tuoi) {
    struct SinhVien *sv = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    if (sv != NULL) {
        strcpy(sv->ma_so, ma_so);
        strcpy(sv->ho_ten, ho_ten);
        sv->tuoi = tuoi;
        sv->next = NULL;
    }
    return sv;
}

// H�m d? th�m m?t sinh vi�n m?i v�o danh s�ch
void them_sinh_vien(struct SinhVien **head_ref, char ma_so[], char ho_ten[], int tuoi) {
    struct SinhVien *new_sinh_vien = tao_sinh_vien(ma_so, ho_ten, tuoi);
    if (new_sinh_vien != NULL) {
        new_sinh_vien->next = *head_ref;
        *head_ref = new_sinh_vien;
    }
}

// H�m d? hi?n th? danh s�ch sinh vi�n
void hien_thi_danh_sach(struct SinhVien *head) {
    printf("Danh sach sinh vien:\n");
    while (head != NULL) {
        printf("Ma so SV: %s\n", head->ma_so);
        printf("Ho va ten: %s\n", head->ho_ten);
        printf("Tuoi: %d\n", head->tuoi);
        printf("------------------\n");
        head = head->next;
    }
}

// H�m d? x�a m?t sinh vi�n t? danh s�ch
void xoa_sinh_vien(struct SinhVien **head_ref, char ma_so[]) {
    struct SinhVien *temp = *head_ref, *prev = NULL;
    if (temp != NULL && strcmp(temp->ma_so, ma_so) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->ma_so, ma_so) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// H�m d? h?y danh s�ch sinh vi�n
void huy_danh_sach(struct SinhVien **head_ref) {
    struct SinhVien *current = *head_ref, *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
    printf("Da huy danh sach sinh vien.\n");
}

int main() {
    struct SinhVien *danh_sach_sv = NULL;
    char lua_chon;
    char ma_so[20], ho_ten[50];
    int tuoi;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Huy danh sach sinh vien\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: \n");
        scanf(" %c", &lua_chon);

        switch (lua_chon) {
            case '1':
                printf("Nhap ma so sinh vien: ");
                scanf("%s", ma_so);
                printf("Nhap ho va ten sinh vien: ");
                scanf("%s", ho_ten);
                printf("Nhap tuoi cua sinh vien: ");
                scanf("%d", &tuoi);
                them_sinh_vien(&danh_sach_sv, ma_so, ho_ten, tuoi);
                printf("Da them sinh vien thanh cong.\n");
                break;
            case '2':
                hien_thi_danh_sach(danh_sach_sv);
                break;
            case '3':
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%s", ma_so);
                xoa_sinh_vien(&danh_sach_sv, ma_so);
                printf("�a xoa sinh vien co ma so %s\n", ma_so);
                break;
            case '4':
                huy_danh_sach(&danh_sach_sv);
                break;
            case '5':
                printf("�a thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    }

    return 0;
}

