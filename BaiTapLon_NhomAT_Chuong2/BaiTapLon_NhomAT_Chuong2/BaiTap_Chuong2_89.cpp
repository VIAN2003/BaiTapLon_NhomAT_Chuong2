#include <stdio.h>

#define MAX_N 50

// Ham tinh tong cac phan tu nam tren duong cheo chinh
int tongDuongCheoChinh(int mat[MAX_N][MAX_N], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mat[i][i];
    }
    return tong;
}

// Ham tinh tong cac phan tu nam tren duong cheo phu
int tongDuongCheoPhu(int mat[MAX_N][MAX_N], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mat[i][n - i - 1];
    }
    return tong;
}

// Ham tinh tong cac phan tu nam phia tren duong cheo chinh
int tongPhiaTrenDuongCheoChinh(int mat[MAX_N][MAX_N], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += mat[i][j];
        }
    }
    return tong;
}

// Ham tinh tong cac phan tu nam phia tren duong cheo phu
int tongPhiaTrenDuongCheoPhu(int mat[MAX_N][MAX_N], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            tong += mat[i][j];
        }
    }
    return tong;
}

// Ham nhap ma tran
void nhapMaTran(int mat[MAX_N][MAX_N], int* n) {
    printf("Nhap so hang va cot (n): ");
    scanf("%d", n);
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            printf("Nhap mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Ham xuat ma tran
void xuatMaTran(int mat[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Ham menu
void menu(int mat[MAX_N][MAX_N], int n) {
    int luaChon;

    while (1) {
        printf("\nChon bai: \n");
        printf("1. Tinh tong cac phan tu tren duong cheo chinh\n");
        printf("2. Tinh tong cac phan tu tren duong cheo phu\n");
        printf("3. Tinh tong cac phan tu phia tren duong cheo chinh\n");
        printf("4. Tinh tong cac phan tu phia tren duong cheo phu\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongDuongCheoChinh(mat, n));
            break;
        case 2:
            printf("Tong cac phan tu tren duong cheo phu: %d\n", tongDuongCheoPhu(mat, n));
            break;
        case 3:
            printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", tongPhiaTrenDuongCheoChinh(mat, n));
            break;
        case 4:
            printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tongPhiaTrenDuongCheoPhu(mat, n));
            break;
        case 0:
            return;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    }
}

int main() {
    int mat[MAX_N][MAX_N];
    int n;

    nhapMaTran(mat, &n);
    xuatMaTran(mat, n);

    menu(mat, n);

    return 0;
}
