#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Ham nhap mang
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

// Ham tim max
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Ham tim min
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Ham dem so chan/le
void demChanLe(int a[], int n, int* chan, int* le) {
    *chan = 0;
    *le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            (*chan)++;
        }
        else {
            (*le)++;
        }
    }
}

// Ham tim kiem tuyen tinh
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Ham tim kiem nhi phan
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Ham dem so phan tu co gia tri bang x
int demGiaTriX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Ham dem so phan tu lon hon x
int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

// Ham tinh tong cac phan tu
int tinhTong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Ham xuat cac so nguyen to
void xuatSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Ham kiem tra so hoan thien
bool laSoHoanThien(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// Ham xuat cac so hoan thien
void xuatSoHoanThien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Ham xuat cac phan tu o vi tri chan/le
void xuatViTriChanLe(int a[], int n, bool chan) {
    for (int i = (chan ? 0 : 1); i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Ham xuat gia tri max/min kem vi tri
void xuatMaxMinViTri(int a[], int n, bool max) {
    int viTri = 0;
    for (int i = 1; i < n; i++) {
        if ((max && a[i] > a[viTri]) || (!max && a[i] < a[viTri])) {
            viTri = i;
        }
    }
    printf("%d o vi tri %d\n", a[viTri], viTri);
}

// Ham ghep hai mang tang dan
void ghepMangTangDan(int a[], int* n, int b[], int m, int c[], int p) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < p) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < p) {
        a[k++] = c[j++];
    }
    *n = k;
}

// Ham sap xep tang dan bang phuong phap Interchange Sort
void interchangeSortTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Ham sap xep giam dan bang phuong phap Interchange Sort
void interchangeSortGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Ham hien thi menu
void hienThiMenu() {
    printf("\n\n1. Nhap/Xuat mang\n");
    printf("2. Tim max/min\n");
    printf("3. Dem so phan tu chan/le\n");
    printf("4. Tim kiem phan tu x\n");
    printf("5. Dem tren a co bao nhieu phan tu x\n");
    printf("6. Dem tren a co bao nhieu phan tu lon hon x\n");
    printf("7. Tinh tong cac phan tu\n");
    printf("8. Xuat cac so nguyen to\n");
    printf("9. Xuat cac so hoan thien\n");
    printf("10. Xuat cac phan tu o vi tri chan/le\n");
    printf("11. Xuat gia tri max/min kem vi tri\n");
    printf("12. Ghep hai day so tang dan\n");
    printf("13. Sap xep tang dan theo PP interchange sort\n");
    printf("14. Sap xep giam dan theo PP interchange sort\n");
    printf("0. Thoat\n");
}

// Ham xu ly menu
void xuLyMenu(int luaChon, int a[], int* n) {
    int x, m, p, chan, le, viTri, b[100], c[100];
    switch (luaChon) {
    case 1:
        nhapMang(a, n);
        printf("Phan tu trong mang: ");
        xuatMang(a, *n);
        break;
    case 2:
        printf("Max: %d\n", timMax(a, *n));
        printf("Min: %d\n", timMin(a, *n));
        break;
    case 3:
        demChanLe(a, *n, &chan, &le);
        printf("So chan: %d\n", chan);
        printf("So le: %d\n", le);
        break;
    case 4:
        printf("Nhap x: ");
        scanf("%d", &x);
        viTri = timKiemTuyenTinh(a, *n, x);
        if (viTri != -1) {
            printf("Tim kiem tuyen tinh: x o vi tri %d\n", viTri);
        }
        else {
            printf("Tim kiem tuyen tinh: x khong co trong mang\n");
        }
        viTri = timKiemNhiPhan(a, *n, x);
        if (viTri != -1) {
            printf("Tim kiem nhi phan: x o vi tri %d\n", viTri);
        }
        else {
            printf("Tim kiem nhi phan: x khong co trong mang\n");
        }
        break;
    case 5:
        printf("Nhap x: ");
        scanf("%d", &x);
        printf("So phan tu bang x: %d\n", demGiaTriX(a, *n, x));
        break;
    case 6:
        printf("Nhap x: ");
        scanf("%d", &x);
        printf("So phan tu lon hon x: %d\n", demLonHonX(a, *n, x));
        break;
    case 7:
        printf("Tong cac phan tu: %d\n", tinhTong(a, *n));
        break;
    case 8:
        printf("So nguyen to trong mang gom: ");
        xuatSoNguyenTo(a, *n);
        break;
    case 9:
        xuatSoHoanThien(a, *n);
        break;
    case 10:
        printf("Phan tu o vi tri chan: ");
        xuatViTriChanLe(a, *n, true);
        printf("Phan tu o vi tri le: ");
        xuatViTriChanLe(a, *n, false);
        break;
    case 11:
        printf("Gia tri max va vi tri: ");
        xuatMaxMinViTri(a, *n, true);
        printf("Gia tri min va vi tri: ");
        xuatMaxMinViTri(a, *n, false);
        break;
    case 12:
        printf("Nhap so luong phan tu cua mang b: ");
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            printf("Nhap phan tu b thu %d: ", i + 1);
            scanf("%d", &b[i]);
        }
        printf("Nhap so luong phan tu cua mang c: ");
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            printf("Nhap phan tu c thu %d: ", i + 1);
            scanf("%d", &c[i]);
        }
        ghepMangTangDan(a, n, b, m, c, p);
        xuatMang(a, *n);
        break;
    case 13:
        interchangeSortTang(a, *n);
        printf("Mang sau khi sap xep tang dan: ");
        xuatMang(a, *n);
        break;
    case 14:
        interchangeSortGiam(a, *n);
        printf("Mang sau khi sap xep giam dan: ");
        xuatMang(a, *n);
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
