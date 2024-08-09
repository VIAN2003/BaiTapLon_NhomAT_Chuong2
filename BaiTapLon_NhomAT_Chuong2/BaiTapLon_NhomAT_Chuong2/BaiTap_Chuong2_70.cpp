#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SINH_VIEN 50


//BAI 2
// Dinh nghia cau truc SinhVien
typedef struct {
    int soThuTu;
    char maSoSinhVien[20];
    char hoTen[50];
    float diemTieuLuan;
    float diemThi;
    float diemTongKet;
    float diemHe4;
} SinhVien;

// Ham nhap thong tin sinh vien
void nhapThongTinSinhVien(SinhVien* sv) {
    printf("Nhap so thu tu: ");
    scanf("%d", &sv->soThuTu);
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->maSoSinhVien);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]s", sv->hoTen);
    printf("Nhap diem tieu luan: ");
    scanf("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi: ");
    scanf("%f", &sv->diemThi);
}

// Ham tinh diem tong ket
void tinhDiemTongKet(SinhVien* sv) {
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThi;
}

// Ham qui doi diem tu he 10 sang he 4
float quiDoiDiemHe4(float diem10) {
    if (diem10 >= 9) return 4.0;
    if (diem10 >= 8) return 3.5;
    if (diem10 >= 7) return 3.0;
    if (diem10 >= 6) return 2.5;
    if (diem10 >= 5) return 2.0;
    if (diem10 >= 4) return 1.0;
    return 0.0;
}

// Ham tinh diem he 4 va cap nhat
void tinhDiemHe4(SinhVien* sv) {
    sv->diemHe4 = quiDoiDiemHe4(sv->diemTongKet);
}

// Ham nhap danh sach sinh vien tu ban phim
void nhapDanhSachSinhVien(SinhVien arr[], int* n) {
    printf("Nhap so luong sinh vien (n <= 50): ");
    scanf("%d", n);
    while (*n < 1 || *n > MAX_SINH_VIEN) {
        printf("So luong sinh vien phai trong khoang tu 1 den 50. Vui long nhap lai: ");
        scanf("%d", n);
    }
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapThongTinSinhVien(&arr[i]);
        tinhDiemTongKet(&arr[i]);
        tinhDiemHe4(&arr[i]);
    }
}

// Ham xuat danh sach sinh vien ra file
void xuatDanhSachSinhVien(SinhVien arr[], int n, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (!file) {
        printf("Khong mo duoc file.\n");
        return;
    }

    fprintf(file, "Danh sach sinh vien:\n");
    fprintf(file, "------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "So thu tu: %d\n", arr[i].soThuTu);
        fprintf(file, "Ma so sinh vien: %s\n", arr[i].maSoSinhVien);
        fprintf(file, "Ho ten: %s\n", arr[i].hoTen);
        fprintf(file, "Diem tieu luan: %.2f\n", arr[i].diemTieuLuan);
        fprintf(file, "Diem thi: %.2f\n", arr[i].diemThi);
        fprintf(file, "Diem tong ket: %.2f\n", arr[i].diemTongKet);
        fprintf(file, "Diem he 4: %.2f\n", arr[i].diemHe4);
        fprintf(file, "------------------------\n");
    }

    fclose(file);
}

// Ham tim sinh vien co diem tong ket cao nhat va thap nhat
void timMaxMin(SinhVien arr[], int n, SinhVien* maxSV, SinhVien* minSV) {
    *maxSV = arr[0];
    *minSV = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].diemTongKet > maxSV->diemTongKet) {
            *maxSV = arr[i];
        }
        if (arr[i].diemTongKet < minSV->diemTongKet) {
            *minSV = arr[i];
        }
    }
}

// Ham dem so sinh vien dat va khong dat
void demSinhVien(SinhVien arr[], int n, int* dat, int* khongDat) {
    *dat = 0;
    *khongDat = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].diemTongKet >= 5.0) {
            (*dat)++;
        }
        else {
            (*khongDat)++;
        }
    }
}

// Ham tinh diem trung binh cua tat ca sinh vien
float tinhDiemTrungBinh(SinhVien arr[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i].diemTongKet;
    }
    return tong / n;
}

// Ham sap xep sinh vien theo diem tong ket tang dan
void sapXepTangDan(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diemTongKet > arr[j].diemTongKet) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham sap xep sinh vien theo diem tong ket giam dan
void sapXepGiamDan(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diemTongKet < arr[j].diemTongKet) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham hien thi menu
void hienThiMenu() {
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Tim sinh vien co diem tong ket cao nhat va thap nhat\n");
    printf("4. Dem so sinh vien dat va khong dat\n");
    printf("5. Qui doi diem sang he 4\n");
    printf("6. Sap xep sinh vien tang dan\n");
    printf("7. Sap xep sinh vien giam dan\n");
    printf("8. Tinh diem trung binh\n");
    printf("0. Thoat\n");
}

// Hàm x? lý menu
void xuLyMenu(int luaChon, SinhVien arr[], int* n) {
    SinhVien maxSV, minSV;
    int dat, khongDat;
    float diemTrungBinh;

    switch (luaChon) {
    case 1:
        nhapDanhSachSinhVien(arr, n);
        break;
    case 2:
        xuatDanhSachSinhVien(arr, *n, "output.txt");
        printf("Danh sach sinh vien da duoc xuat ra file 'output.txt'\n");
        break;
    case 3:
        timMaxMin(arr, *n, &maxSV, &minSV);
        printf("Sinh vien diem cao nhat:\n");
        printf("So thu tu: %d, Ma so: %s, Ho ten: %s, Diem tong ket: %.2f\n",
            maxSV.soThuTu, maxSV.maSoSinhVien, maxSV.hoTen, maxSV.diemTongKet);
        printf("Sinh vien diem thap nhat:\n");
        printf("So thu tu: %d, Ma so: %s, Ho ten: %s, Diem tong ket: %.2f\n",
            minSV.soThuTu, minSV.maSoSinhVien, minSV.hoTen, minSV.diemTongKet);
        break;
    case 4:
        demSinhVien(arr, *n, &dat, &khongDat);
        printf("So sinh vien dat: %d\n", dat);
        printf("So sinh vien khong dat: %d\n", khongDat);
        break;
    case 5:
        for (int i = 0; i < *n; i++) {
            tinhDiemHe4(&arr[i]);
        }
        printf("Diem he 4 da duoc cap nhat.\n");
        break;
    case 6:
        sapXepTangDan(arr, *n);
        printf("Danh sach sinh vien sau khi sap xep tang dan:\n");
        xuatDanhSachSinhVien(arr, *n, "output.txt");
        break;
    case 7:
        sapXepGiamDan(arr, *n);
        printf("Danh sach sinh vien sau khi sap xep giam dan:\n");
        xuatDanhSachSinhVien(arr, *n, "output.txt");
        break;
    case 8:
        diemTrungBinh = tinhDiemTrungBinh(arr, *n);
        printf("Diem trung binh cua tat ca sinh vien: %.2f\n", diemTrungBinh);
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
    SinhVien arr[MAX_SINH_VIEN];
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
