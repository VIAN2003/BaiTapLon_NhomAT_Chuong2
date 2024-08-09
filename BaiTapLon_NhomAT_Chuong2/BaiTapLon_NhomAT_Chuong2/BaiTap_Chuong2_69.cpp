#include <stdio.h>


//BAI 1
// Dinh nghia cau truc phan so
typedef struct {
    int tu;  // Tu so
    int mau; // Mau so
} PhanSo;

// Ham nhap phan so
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

// Ham xuat phan so
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

// Ham tinh uoc chung lon nhat (UCLN) dung de toi gian phan so
int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

// Ham toi gian phan so
void toiGianPhanSo(PhanSo* ps) {
    int uclnPS = ucln(ps->tu, ps->mau);
    ps->tu /= uclnPS;
    ps->mau /= uclnPS;
    if (ps->mau < 0) {  // Dam bao mau so luon duong
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

// Ham nhap danh sach cac phan so
void nhapDanhSachPhanSo(PhanSo arr[], int* n) {
    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", n);
    while (*n < 1 || *n > 50) {
        printf("So luong phan so phai trong khoang tu 1 den 50. Vui long nhap lai: ");
        scanf("%d", n);
    }
    for (int i = 0; i < *n; i++) {
        printf("\nNhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&arr[i]);
        toiGianPhanSo(&arr[i]); // Toi gian phan so ngay khi nhap
    }
}

// Ham xuat danh sach cac phan so
void xuatDanhSachPhanSo(PhanSo arr[], int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(arr[i]);
        printf(" ");
    }
    printf("\n");
}

// Ham tinh gia tri phan so
double giaTriPhanSo(PhanSo ps) {
    return (double)ps.tu / ps.mau;
}

// Ham tim phan so lon nhat va nho nhat
void timMaxMinPhanSo(PhanSo arr[], int n, PhanSo* maxPS, PhanSo* minPS) {
    *maxPS = arr[0];
    *minPS = arr[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(arr[i]) > giaTriPhanSo(*maxPS)) {
            *maxPS = arr[i];
        }
        if (giaTriPhanSo(arr[i]) < giaTriPhanSo(*minPS)) {
            *minPS = arr[i];
        }
    }
}

// Ham tinh tong cac phan so
PhanSo tongPhanSo(PhanSo arr[], int n) {
    PhanSo tong = { 0, 1 }; // Khoi tao phan so 0/1
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * arr[i].mau + arr[i].tu * tong.mau;
        tong.mau = tong.mau * arr[i].mau;
        toiGianPhanSo(&tong);
    }
    return tong;
}

// Ham tinh tich cac phan so
PhanSo tichPhanSo(PhanSo arr[], int n) {
    PhanSo tich = { 1, 1 }; // Khoi tao phan so 1/1
    for (int i = 0; i < n; i++) {
        tich.tu = tich.tu * arr[i].tu;
        tich.mau = tich.mau * arr[i].mau;
        toiGianPhanSo(&tich);
    }
    return tich;
}

// Ham xuat nghich dao cua cac phan so
void xuatNghichDaoPhanSo(PhanSo arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i].tu != 0) {
            PhanSo nghichDao = { arr[i].mau, arr[i].tu };
            toiGianPhanSo(&nghichDao);
            xuatPhanSo(nghichDao);
        }
        else {
            printf("N/A"); // Nghich dao cua phan so 0 khong xac dinh
        }
        printf(" ");
    }
    printf("\n");
}

// Ham sap xep phan so theo thu tu tang dan
void sapXepTangDan(PhanSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriPhanSo(arr[i]) > giaTriPhanSo(arr[j])) {
                PhanSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham sap xep phan so theo thu tu giam dan
void sapXepGiamDan(PhanSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriPhanSo(arr[i]) < giaTriPhanSo(arr[j])) {
                PhanSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham hien thi menu
void hienThiMenu() {
    printf("\n1. Nhap danh sach cac phan so\n");
    printf("2. Xuat danh sach cac phan so\n");
    printf("3. Tim phan so lon nhat va nho nhat\n");
    printf("4. Tinh tong cac phan so\n");
    printf("5. Tinh tich cac phan so\n");
    printf("6. Xuat nghich dao cua cac phan so\n");
    printf("7. Sap xep tang dan\n");
    printf("8. Sap xep giam dan\n");
    printf("0. Thoat\n");
}

// Ham xu ly menu
void xuLyMenu(int luaChon, PhanSo arr[], int* n) {
    PhanSo maxPS, minPS;
    PhanSo kq;
    switch (luaChon) {
    case 1:
        nhapDanhSachPhanSo(arr, n);
        break;
    case 2:
        printf("\nDanh sach phan so: ");
        xuatDanhSachPhanSo(arr, *n);
        break;
    case 3:
        timMaxMinPhanSo(arr, *n, &maxPS, &minPS);
        printf("\nPhan so lon nhat: ");
        xuatPhanSo(maxPS);
        printf("\nPhan so nho nhat: ");
        xuatPhanSo(minPS);
        printf("\n");
        break;
    case 4:
        kq = tongPhanSo(arr, *n);
        printf("\nTong cac phan so: ");
        xuatPhanSo(kq);
        printf("\n");
        break;
    case 5:
        kq = tichPhanSo(arr, *n);
        printf("\nTich cac phan so: ");
        xuatPhanSo(kq);
        printf("\n");
        break;
    case 6:
        printf("\nNghich dao cac phan so: ");
        xuatNghichDaoPhanSo(arr, *n);
        break;
    case 7:
        sapXepTangDan(arr, *n);
        printf("\nDanh sach phan so sau khi sap xep tang dan: ");
        xuatDanhSachPhanSo(arr, *n);
        break;
    case 8:
        sapXepGiamDan(arr, *n);
        printf("\nDanh sach phan so sau khi sap xep giam dan: ");
        xuatDanhSachPhanSo(arr, *n);
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
    PhanSo arr[50];
    int n = 0;
    int luaChon;
    do {
        hienThiMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        xuLyMenu(luaChon, arr, &n);
    } while (luaChon != 0);
    return 0;
}
