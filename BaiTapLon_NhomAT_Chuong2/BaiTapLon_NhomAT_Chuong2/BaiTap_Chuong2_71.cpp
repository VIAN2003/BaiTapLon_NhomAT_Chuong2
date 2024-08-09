#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 50
#define MAX_MON_HOC 5

//BAI 3
// Cau truc mon hoc
typedef struct {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
} MonHoc;

// Cau truc sinh vien
typedef struct {
    char maSoSinhVien[20];
    char hoTen[50];
    MonHoc monHoc[MAX_MON_HOC];
    float diemTrungBinhTichLuy;
} SinhVien;

// Ham nhap thong tin mon hoc
void nhapMonHoc(MonHoc* mh) {
    printf("Nhap ma mon hoc: ");
    scanf("%s", mh->maMon);
    printf("Nhap ten mon hoc: ");
    scanf(" %[^\n]s", mh->tenMon);
    printf("Nhap so tin chi: ");
    scanf("%d", &mh->soTinChi);
    printf("Nhap diem: ");
    scanf("%f", &mh->diem);
}

// Ham nhap thong tin sinh vien
void nhapThongTinSinhVien(SinhVien* sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->maSoSinhVien);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]s", sv->hoTen);
    for (int i = 0; i < MAX_MON_HOC; i++) {
        printf("Nhap thong tin mon hoc %d:\n", i + 1);
        nhapMonHoc(&sv->monHoc[i]);
    }
    printf("Nhap diem trung binh tich luy: ");
    scanf("%f", &sv->diemTrungBinhTichLuy);
}

// Ham xuat thong tin mon hoc
void xuatMonHoc(MonHoc mh) {
    printf("Ma mon hoc: %s\n", mh.maMon);
    printf("Ten mon hoc: %s\n", mh.tenMon);
    printf("So tin chi: %d\n", mh.soTinChi);
    printf("Diem: %.2f\n", mh.diem);
}

// Ham xuat thong tin sinh vien
void xuatThongTinSinhVien(SinhVien sv) {
    printf("Ma so sinh vien: %s\n", sv.maSoSinhVien);
    printf("Ho ten sinh vien: %s\n", sv.hoTen);
    for (int i = 0; i < MAX_MON_HOC; i++) {
        printf("Thong tin mon hoc %d:\n", i + 1);
        xuatMonHoc(sv.monHoc[i]);
    }
    printf("Diem trung binh tich luy: %.2f\n", sv.diemTrungBinhTichLuy);
}

// Ham nhap danh sach sinh vien
void nhapDanhSachSinhVien(SinhVien arr[], int* n) {
    printf("Nhap so luong sinh vien (n <= %d): ", MAX_SINH_VIEN);
    scanf("%d", n);
    while (*n < 1 || *n > MAX_SINH_VIEN) {
        printf("So luong sinh vien phai trong khoang tu 1 den %d. Vui long nhap lai: ", MAX_SINH_VIEN);
        scanf("%d", n);
    }
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapThongTinSinhVien(&arr[i]);
    }
}

// Ham xuat danh sach sinh vien
void xuatDanhSachSinhVien(SinhVien arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Thong tin sinh vien thu %d:\n", i + 1);
        xuatThongTinSinhVien(arr[i]);
        printf("------------------------\n");
    }
}

// Ham tim sinh vien theo ma so sinh vien
int timSinhVienTheoMa(SinhVien arr[], int n, char* maSoSinhVien) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].maSoSinhVien, maSoSinhVien) == 0) {
            return i;
        }
    }
    return -1; // Khong tim thay
}

// Ham tim sinh vien co diem trung binh cao nhat
int timSinhVienDiemCaoNhat(SinhVien arr[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].diemTrungBinhTichLuy > arr[index].diemTrungBinhTichLuy) {
            index = i;
        }
    }
    return index;
}

// Ham tim sinh vien co diem trung binh thap nhat
int timSinhVienDiemThapNhat(SinhVien arr[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].diemTrungBinhTichLuy < arr[index].diemTrungBinhTichLuy) {
            index = i;
        }
    }
    return index;
}

// Ham them sinh vien vao danh sach
void themSinhVien(SinhVien arr[], int* n, SinhVien sv) {
    if (*n < MAX_SINH_VIEN) {
        arr[*n] = sv;
        (*n)++;
    }
    else {
        printf("Danh sach sinh vien da day.\n");
    }
}

// Ham xoa sinh vien khoi danh sach
void xoaSinhVien(SinhVien arr[], int* n, char* maSoSinhVien) {
    int index = timSinhVienTheoMa(arr, *n, maSoSinhVien);
    if (index == -1) {
        printf("Sinh vien voi ma so %s khong ton tai.\n", maSoSinhVien);
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Ham sap xep danh sach sinh vien theo diem trung binh tang dan
void sapXepTangDan(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diemTrungBinhTichLuy > arr[j].diemTrungBinhTichLuy) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham sap xep danh sach sinh vien theo diem trung binh giam dan
void sapXepGiamDan(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].diemTrungBinhTichLuy < arr[j].diemTrungBinhTichLuy) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ham xep loai hoc tap
void xepLoai(SinhVien sv) {
    if (sv.diemTrungBinhTichLuy >= 8.5) {
        printf("Sinh vien %s xep loai Xuat sac.\n", sv.hoTen);
    }
    else if (sv.diemTrungBinhTichLuy >= 7.0) {
        printf("Sinh vien %s xep loai Gioi.\n", sv.hoTen);
    }
    else if (sv.diemTrungBinhTichLuy >= 5.5) {
        printf("Sinh vien %s xep loai Kha.\n", sv.hoTen);
    }
    else if (sv.diemTrungBinhTichLuy >= 4.0) {
        printf("Sinh vien %s xep loai Trung binh.\n", sv.hoTen);
    }
    else {
        printf("Sinh vien %s xep loai Yeu.\n", sv.hoTen);
    }
}

// Ham thong ke so mon dau rot cua sinh vien
void thongKeMon(SinhVien sv) {
    int soMonDat = 0, soMonRot = 0;
    for (int i = 0; i < MAX_MON_HOC; i++) {
        if (sv.monHoc[i].diem >= 5.0) {
            soMonDat++;
        }
        else {
            soMonRot++;
        }
    }
    printf("Sinh vien %s co %d mon dat va %d mon rot.\n", sv.hoTen, soMonDat, soMonRot);
}

// Ham hien thi menu
void hienThiMenu() {
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Tim sinh vien theo ma so\n");
    printf("4. Tim sinh vien diem cao nhat\n");
    printf("5. Tim sinh vien diem thap nhat\n");
    printf("6. Them sinh vien\n");
    printf("7. Xoa sinh vien\n");
    printf("8. Sap xep sinh vien tang dan\n");
    printf("9. Sap xep sinh vien giam dan\n");
    printf("10. Xep loai hoc tap\n");
    printf("11. Thong ke so mon dau rot\n");
    printf("0. Thoat\n");
}

// Ham xu ly menu
void xuLyMenu(int luaChon, SinhVien arr[], int* n) {
    SinhVien sv;
    int index;
    char maSoSinhVien[20];

    switch (luaChon) {
    case 1:
        nhapDanhSachSinhVien(arr, n);
        break;
    case 2:
        xuatDanhSachSinhVien(arr, *n);
        break;
    case 3:
        printf("Nhap ma so sinh vien: ");
        scanf("%s", maSoSinhVien);
        index = timSinhVienTheoMa(arr, *n, maSoSinhVien);
        if (index != -1) {
            printf("Thong tin sinh vien:\n");
            xuatThongTinSinhVien(arr[index]);
        }
        else {
            printf("Sinh vien voi ma so %s khong ton tai.\n", maSoSinhVien);
        }
        break;
    case 4:
        index = timSinhVienDiemCaoNhat(arr, *n);
        printf("Sinh vien diem cao nhat:\n");
        xuatThongTinSinhVien(arr[index]);
        break;
    case 5:
        index = timSinhVienDiemThapNhat(arr, *n);
        printf("Sinh vien diem thap nhat:\n");
        xuatThongTinSinhVien(arr[index]);
        break;
    case 6:
        printf("Nhap thong tin sinh vien moi:\n");
        nhapThongTinSinhVien(&sv);
        themSinhVien(arr, n, sv);
        break;
    case 7:
        printf("Nhap ma so sinh vien can xoa: ");
        scanf("%s", maSoSinhVien);
        xoaSinhVien(arr, n, maSoSinhVien);
        break;
    case 8:
        sapXepTangDan(arr, *n);
        printf("Danh sach sinh vien sau khi sap xep tang dan:\n");
        xuatDanhSachSinhVien(arr, *n);
        break;
    case 9:
        sapXepGiamDan(arr, *n);
        printf("Danh sach sinh vien sau khi sap xep giam dan:\n");
        xuatDanhSachSinhVien(arr, *n);
        break;
    case 10:
        for (int i = 0; i < *n; i++) {
            xepLoai(arr[i]);
        }
        break;
    case 11:
        for (int i = 0; i < *n; i++) {
            thongKeMon(arr[i]);
        }
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
