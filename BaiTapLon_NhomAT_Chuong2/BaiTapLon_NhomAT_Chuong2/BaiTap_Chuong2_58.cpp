#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void nhapMang(int a[], int* n) {
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Ham xuat mang
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Ham dem so phan tu nguyen to trong mang
int demSoNguyenTo(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            count++;
        }
    }
    return count;
}

// Ham kiem tra tat ca cac chu so cua so la so le
bool tatCaSoLe(int num) {
    if (num == 0) return false;
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) return false;
        num /= 10;
    }
    return true;
}

// Ham xuat cac phan tu ma tong chu so cua no la so le
void xuatSoChuSoLe(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (tatCaSoLe(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Ham tim vi tri so lon nhat cuoi cung
int viTriMaxCuoiCung(int a[], int n) {
    int max = a[0];
    int viTri = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= max) {
            max = a[i];
            viTri = i;
        }
    }
    return viTri;
}

// Ham kiem tra mang co toan so chan
bool mangToanChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra mang co phai la day so chan le xen ke khong
bool mangChanLeXenKe(int a[], int n) {
    if (n < 2) return true;
    bool chan = a[0] % 2 == 0;
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0) == chan) {
            return false;
        }
        chan = !chan;
    }
    return true;
}

// Ham kiem tra mang co chua toan so nguyen to
bool mangToanSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!laSoNguyenTo(a[i])) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra mang co doi xung khong
bool mangDoiXung(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        if (a[left] != a[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Ham kiem tra mang co tang dan khong
bool mangTangDan(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra mang co giam dan khong
bool mangGiamDan(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra mang co tang dan, giam dan, hoac khong tang khong giam
void kiemTraMang(int a[], int n) {
    if (mangTangDan(a, n)) {
        printf("Mang tang dan.\n");
    }
    else if (mangGiamDan(a, n)) {
        printf("Mang giam dan.\n");
    }
    else {
        printf("Mang khong tang khong giam.\n");
    }
}

// Ham hien thi menu
void hienThiMenu() {
    printf("\n1. Nhap/Xuat mang\n");
    printf("2. Dem so phan tu la so nguyen to\n");
    printf("3. Xuat cac phan tu ma tung chu so la so le\n");
    printf("4. Tim vi tri so lon nhat cuoi cung\n");
    printf("5. Kiem tra mang toan chan\n");
    printf("6. Kiem tra mang chan le xen ke\n");
    printf("7. Kiem tra mang co toan so nguyen to\n");
    printf("8. Kiem tra mang doi xung\n");
    printf("9. Kiem tra mang tang dan/giam dan/khong tang khong giam\n");
    printf("0. Thoat\n");
}

// Ham xu ly menu
void xuLyMenu(int luaChon, int a[], int* n) {
    int x, m, p, chan, le, viTri;
    int b[100], c[100];
    switch (luaChon) {
    case 1:
        nhapMang(a, n);
        printf("Phan tu trong mang: ");
        xuatMang(a, *n);
        break;
    case 2:
        printf("So phan tu la so nguyen to: %d\n", demSoNguyenTo(a, *n));
        break;
    case 3:
        printf("So le trong trong mang gom: ");
        xuatSoChuSoLe(a, *n);
        break;
    case 4:
        viTri = viTriMaxCuoiCung(a, *n);
        printf("Vi tri so lon nhat cuoi cung: %d\n", viTri);
        break;
    case 5:
        printf("Mang toan chan: %s\n", mangToanChan(a, *n) ? "Co" : "Khong");
        break;
    case 6:
        printf("Mang chan le xen ke: %s\n", mangChanLeXenKe(a, *n) ? "Co" : "Khong");
        break;
    case 7:
        printf("Mang toan so nguyen to: %s\n", mangToanSoNguyenTo(a, *n) ? "Co" : "Khong");
        break;
    case 8:
        printf("Mang doi xung: %s\n", mangDoiXung(a, *n) ? "Co" : "Khong");
        break;
    case 9:
        kiemTraMang(a, *n);
        break;
    case 0:
        printf("Thoat\n");
        break;
    default:
        printf("Lua chon khong hop le\n");
        break;
    }
}

int main() {
    int a[200], n = 0;
    int luaChon;
    do {
        hienThiMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        xuLyMenu(luaChon, a, &n);
    } while (luaChon != 0);
    return 0;
}
