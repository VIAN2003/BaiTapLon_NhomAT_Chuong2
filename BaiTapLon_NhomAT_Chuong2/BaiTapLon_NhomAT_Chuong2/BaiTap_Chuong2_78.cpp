#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#define MAX_M 50
#define MAX_N 50

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Ham kiem tra so hoan thien
bool laSoHoanThien(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

// Ham lay chu so dau cua so nguyen
int layChuSoDau(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

// Ham nhap ma tran
void nhapMaTran(int mat[MAX_M][MAX_N], int* m, int* n) {
    printf("Nhap so hang (m): ");
    scanf("%d", m);
    printf("Nhap so cot (n): ");
    scanf("%d", n);
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("Nhap mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Ham xuat ma tran
void xuatMaTran(int mat[MAX_M][MAX_N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Bai 1: Tinh tong cac phan tu co chu so dau la chu so le
void tongPhanTuChuSoDauLe(int mat[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (layChuSoDau(mat[i][j]) % 2 != 0) {
                tong += mat[i][j];
            }
        }
    }
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tong);
}

// Bai 2: Liet ke cac so hoan thien trong ma tran
void lietKeSoHoanThien(int mat[MAX_M][MAX_N], int m, int n) {
    printf("Cac so hoan thien trong ma tran:\n");
    bool coSoHoanThien = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(mat[i][j])) {
                printf("%d ", mat[i][j]);
                coSoHoanThien = true;
            }
        }
    }
    if (!coSoHoanThien) {
        printf("Khong co so hoan thien trong ma tran.\n");
    }
    printf("\n");
}

// Bai 3: Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no
void tongPhanTuLonHonTriTuyetDoiSau(int mat[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (mat[i][j] > abs(mat[i][j + 1])) {
                tong += mat[i][j];
            }
        }
    }
    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tong);
}

// Bai 4: Tinh tong gia tri tren dong k cua ma tran
void tongGiaTriTrenDongK(int mat[MAX_M][MAX_N], int n, int k) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += mat[k][j];
    }
    printf("Tong gia tri tren dong %d: %d\n", k, tong);
}

// Bai 5: Tinh tong cac gia tri nam tren bien cua ma tran
void tongGiaTriTrenBien(int mat[MAX_M][MAX_N], int m, int n) {
    int tong = 0;

    // Tong cac gia tri o hang dau tien va hang cuoi cung
    for (int j = 0; j < n; j++) {
        tong += mat[0][j];
        if (m > 1) tong += mat[m - 1][j];
    }

    // Tong cac gia tri o cot dau tien va cot cuoi cung (tru cac gia tri da tinh o tren)
    for (int i = 1; i < m - 1; i++) {
        tong += mat[i][0];
        if (n > 1) tong += mat[i][n - 1];
    }

    printf("Tong cac gia tri tren bien ma tran: %d\n", tong);
}

// Bai 6: Dem tan suat xuat hien cua 1 gia tri x trong ma tran
void demTanSuatX(int mat[MAX_M][MAX_N], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == x) {
                dem++;
            }
        }
    }
    printf("Gia tri %d xuat hien %d lan\n", x, dem);
}

// Bai 7: Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to
void demSoLuongPhanTu(int mat[MAX_M][MAX_N], int m, int n) {
    int soChan = 0, soLe = 0, soAm = 0, soDuong = 0, soNguyenTo = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = mat[i][j];
            if (value % 2 == 0) {
                soChan++;
            }
            else {
                soLe++;
            }
            if (value < 0) {
                soAm++;
            }
            else if (value > 0) {
                soDuong++;
            }
            if (laSoNguyenTo(value)) {
                soNguyenTo++;
            }
        }
    }

    printf("So phan tu chan: %d\n", soChan);
    printf("So phan tu le: %d\n", soLe);
    printf("So phan tu am: %d\n", soAm);
    printf("So phan tu duong: %d\n", soDuong);
    printf("So phan tu nguyen to: %d\n", soNguyenTo);
}

// Ham menu
void menu(int mat[MAX_M][MAX_N], int m, int n) {
    int luaChon, k, x;

    while (1) {
        printf("\nChon bai: \n");
        printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("2. Liet ke cac so hoan thien trong ma tran\n");
        printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau\n");
        printf("4. Tinh tong gia tri tren dong k\n");
        printf("5. Tinh tong cac gia tri tren bien ma tran\n");
        printf("6. Dem tan suat xuat hien cua 1 gia tri x\n");
        printf("7. Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            tongPhanTuChuSoDauLe(mat, m, n);
            break;
        case 2:
            lietKeSoHoanThien(mat, m, n);
            break;
        case 3:
            tongPhanTuLonHonTriTuyetDoiSau(mat, m, n);
            break;
        case 4:
            printf("Nhap dong k: ");
            scanf("%d", &k);
            if (k >= 0 && k < m) {
                tongGiaTriTrenDongK(mat, n, k);
            }
            else {
                printf("Chi so dong k khong hop le.\n");
            }
            break;
        case 5:
            tongGiaTriTrenBien(mat, m, n);
            break;
        case 6:
            printf("Nhap gia tri x: ");
            scanf("%d", &x);
            demTanSuatX(mat, m, n, x);
            break;
        case 7:
            demSoLuongPhanTu(mat, m, n);
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
    int mat[MAX_M][MAX_N];
    int m, n;

    nhapMaTran(mat, &m, &n);
    xuatMaTran(mat, m, n);

    menu(mat, m, n);

    return 0;
}
