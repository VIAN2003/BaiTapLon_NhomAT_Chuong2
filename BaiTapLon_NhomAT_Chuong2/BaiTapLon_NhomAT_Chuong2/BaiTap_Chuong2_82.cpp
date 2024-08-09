#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

// Bai 1: Liet ke cac cot co tong nho nhat trong ma tran
void lietKeCotTongNhoNhat(int mat[MAX_M][MAX_N], int m, int n) {
    int minSum = INT_MAX;
    int sum;

    // Tinh tong tung cot
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += mat[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }

    // Liet ke cot co tong nho nhat
    printf("Cac cot co tong nho nhat (%d):\n", minSum);
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += mat[i][j];
        }
        if (sum == minSum) {
            printf("Cot %d\n", j);
        }
    }
}

// Bai 2: Liet ke cac dong co nhieu so hoan thien nhat trong ma tran
void lietKeDongSoHoanThienNhat(int mat[MAX_M][MAX_N], int m, int n) {
    int maxCount = 0;
    int count;

    // Tinh so luong so hoan thien trong tung dong
    for (int i = 0; i < m; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(mat[i][j])) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }

    // Liet ke cac dong co nhieu so hoan thien nhat
    printf("Cac dong co nhieu so hoan thien nhat (%d):\n", maxCount);
    for (int i = 0; i < m; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(mat[i][j])) {
                count++;
            }
        }
        if (count == maxCount) {
            printf("Dong %d\n", i);
        }
    }
}

// Bai 3: Liet ke chi so cac dong chua toan gia tri chan
void lietKeDongToanChan(int mat[MAX_M][MAX_N], int m, int n) {
    printf("Cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        bool toanChan = true;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            printf("Dong %d\n", i);
        }
    }
}

// Bai 4: Tim gia tri xuat hien nhieu nhat trong ma tran
void timGiaTriXuatHienNhieuNhat(int mat[MAX_M][MAX_N], int m, int n) {
    int freq[MAX_M * MAX_N] = { 0 };  // Mang dem tan suat
    int maxFreq = 0;
    int maxValue = 0;

    // Dem tan suat cua tung gia tri
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = mat[i][j];
            freq[value]++;
            if (freq[value] > maxFreq) {
                maxFreq = freq[value];
                maxValue = value;
            }
        }
    }

    printf("Gia tri xuat hien nhieu nhat: %d (xuat hien %d lan)\n", maxValue, maxFreq);
}

// Bai 5: Tim so nguyen to nho nhat trong ma tran
void timSoNguyenToNhoNhat(int mat[MAX_M][MAX_N], int m, int n) {
    int minPrime = INT_MAX;

    // Tim so nguyen to nho nhat
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoNguyenTo(mat[i][j]) && mat[i][j] < minPrime) {
                minPrime = mat[i][j];
            }
        }
    }

    if (minPrime == INT_MAX) {
        printf("Khong co so nguyen to trong ma tran.\n");
    }
    else {
        printf("So nguyen to nho nhat: %d\n", minPrime);
    }
}

// Bai 6: Tim phan tu lon (nho) nhat trong dong thu k
void timPhanTuLonNhatTrongDongK(int mat[MAX_M][MAX_N], int n, int k) {
    int max = INT_MIN;
    for (int j = 0; j < n; j++) {
        if (mat[k][j] > max) {
            max = mat[k][j];
        }
    }
    printf("Phan tu lon nhat trong dong %d: %d\n", k, max);
}

void timPhanTuNhoNhatTrongDongK(int mat[MAX_M][MAX_N], int n, int k) {
    int min = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (mat[k][j] < min) {
            min = mat[k][j];
        }
    }
    printf("Phan tu nho nhat trong dong %d: %d\n", k, min);
}

// Bai 7: Tim phan tu lon (nho) nhat trong cot thu k
void timPhanTuLonNhatTrongCotK(int mat[MAX_M][MAX_N], int m, int k) {
    int max = INT_MIN;
    for (int i = 0; i < m; i++) {
        if (mat[i][k] > max) {
            max = mat[i][k];
        }
    }
    printf("Phan tu lon nhat trong cot %d: %d\n", k, max);
}

void timPhanTuNhoNhatTrongCotK(int mat[MAX_M][MAX_N], int m, int k) {
    int min = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (mat[i][k] < min) {
            min = mat[i][k];
        }
    }
    printf("Phan tu nho nhat trong cot %d: %d\n", k, min);
}

// Ham menu
void menu(int mat[MAX_M][MAX_N], int m, int n) {
    int luaChon, k;

    while (1) {
        printf("\nChon bai: \n");
        printf("1. Liet ke cac cot co tong nho nhat\n");
        printf("2. Liet ke cac dong co nhieu so hoan thien nhat\n");
        printf("3. Liet ke chi so cac dong chua toan gia tri chan\n");
        printf("4. Tim gia tri xuat hien nhieu nhat\n");
        printf("5. Tim so nguyen to nho nhat\n");
        printf("6. Tim phan tu lon (nho) nhat trong dong thu k\n");
        printf("7. Tim phan tu lon (nho) nhat trong cot thu k\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            lietKeCotTongNhoNhat(mat, m, n);
            break;
        case 2:
            lietKeDongSoHoanThienNhat(mat, m, n);
            break;
        case 3:
            lietKeDongToanChan(mat, m, n);
            break;
        case 4:
            timGiaTriXuatHienNhieuNhat(mat, m, n);
            break;
        case 5:
            timSoNguyenToNhoNhat(mat, m, n);
            break;
        case 6:
            printf("Nhap dong k: ");
            scanf("%d", &k);
            if (k >= 0 && k < m) {
                timPhanTuLonNhatTrongDongK(mat, n, k);
                timPhanTuNhoNhatTrongDongK(mat, n, k);
            }
            else {
                printf("Chi so dong k khong hop le.\n");
            }
            break;
        case 7:
            printf("Nhap cot k: ");
            scanf("%d", &k);
            if (k >= 0 && k < n) {
                timPhanTuLonNhatTrongCotK(mat, m, k);
                timPhanTuNhoNhatTrongCotK(mat, m, k);
            }
            else {
                printf("Chi so cot k khong hop le.\n");
            }
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
