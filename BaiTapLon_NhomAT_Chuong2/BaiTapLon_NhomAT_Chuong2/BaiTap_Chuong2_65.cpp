#include <stdio.h>

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

// Ham tinh tong cua hai phan so
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

// Ham tinh hieu cua hai phan so
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

// Ham tinh tich cua hai phan so
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

// Ham tinh thuong cua hai phan so
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    toiGianPhanSo(&kq);
    return kq;
}

// Ham hien thi menu
void hienThiMenu() {
    printf("1. Nhap hai phan so\n");
    printf("2. Tinh tong, hieu, tich, thuong\n");
    printf("0. Thoat\n");
}

// Ham xu ly menu
void xuLyMenu(int luaChon, PhanSo* ps1, PhanSo* ps2) {
    PhanSo kq;
    switch (luaChon) {
    case 1:
        printf("Nhap phan so thu 1:\n");
        nhapPhanSo(ps1);
        printf("\nNhap phan so thu 2:\n");
        nhapPhanSo(ps2);
        printf("\nPhan so thu 1: ");
        xuatPhanSo(*ps1);
        printf("\nPhan so thu 2: ");
        xuatPhanSo(*ps2);
        printf("\n\n");
        break;
    case 2:
        printf("\nTong: ");
        kq = tongPhanSo(*ps1, *ps2);
        xuatPhanSo(kq);
        printf("\n");

        printf("\nHieu: ");
        kq = hieuPhanSo(*ps1, *ps2);
        xuatPhanSo(kq);
        printf("\n");

        printf("\nTich: ");
        kq = tichPhanSo(*ps1, *ps2);
        xuatPhanSo(kq);
        printf("\n");

        printf("\nThuong: ");
        kq = thuongPhanSo(*ps1, *ps2);
        xuatPhanSo(kq);
        printf("\n\n");
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
    PhanSo ps1, ps2;
    int luaChon;
    do {
        hienThiMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        xuLyMenu(luaChon, &ps1, &ps2);
    } while (luaChon != 0);
    return 0;
}
