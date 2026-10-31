#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
} MatHang;

MatHang ds[MAX];
int n = 0;

void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int timViTriTheoMa(int ma) {
    int i;

    for (i = 0; i < n; i++) {
        if (ds[i].maHang == ma) {
            return i;
        }
    }

    return -1;
}

void nhapTen(char ten[]) {
    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < 49) {
            ten[i] = c;
            i++;
        }
    }

    ten[i] = '\0';
}

void nhapSoLuongDonGia(MatHang *mh) {

    do {
        printf("Nhap so luong: ");
        scanf("%d", &mh->soLuong);
        xoaBoDem();

        if (mh->soLuong < 0) {
            printf("So luong phai >= 0!\n");
        }

    } while (mh->soLuong < 0);

    do {
        printf("Nhap don gia: ");
        scanf("%f", &mh->donGia);
        xoaBoDem();

        if (mh->donGia <= 0) {
            printf("Don gia phai > 0!\n");
        }

    } while (mh->donGia <= 0);
}

void nhapThongTin(MatHang *mh) {

    printf("Nhap ten mat hang: ");
    nhapTen(mh->tenHang);

    nhapSoLuongDonGia(mh);
}

void inTieuDe() {
    printf("\n");
    printf("%-10s %-25s %-12s %-15s %-15s\n",
           "Ma", "Ten mat hang", "So luong",
           "Don gia", "Thanh tien");

    printf("--------------------------------------------------------------------------\n");
}

void inMotMatHang(MatHang mh) {
    float thanhTien;

    thanhTien = mh.soLuong * mh.donGia;

    printf("%-10d %-25s %-12d %-15.0f %-15.0f\n",
           mh.maHang, mh.tenHang, mh.soLuong,
           mh.donGia, thanhTien);
}

void themMatHang() {
    MatHang mh;

    if (n >= MAX) {
        printf("Danh sach da day!\n");
        return;
    }

    printf("Nhap ma mat hang: ");
    scanf("%d", &mh.maHang);
    xoaBoDem();

    if (timViTriTheoMa(mh.maHang) != -1) {
        printf("Ma mat hang da ton tai!\n");
        return;
    }

    nhapThongTin(&mh);

    ds[n] = mh;
    n++;

    printf("Them mat hang thanh cong!\n");
}

void hienThiDanhSach() {
    int i;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    inTieuDe();

    for (i = 0; i < n; i++) {
        inMotMatHang(ds[i]);
    }
}

void capNhatMatHang() {
    int ma;
    int viTri;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("Nhap ma mat hang can cap nhat: ");
    scanf("%d", &ma);
    xoaBoDem();

    viTri = timViTriTheoMa(ma);

    if (viTri == -1) {
        printf("Khong tim thay mat hang!\n");
        return;
    }

    printf("Nhap thong tin moi:\n");

    nhapThongTin(&ds[viTri]);

    printf("Cap nhat thanh cong!\n");
}

void xoaMatHang() {
    int ma;
    int viTri;
    int i;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("Nhap ma mat hang can xoa: ");
    scanf("%d", &ma);
    xoaBoDem();

    viTri = timViTriTheoMa(ma);

    if (viTri == -1) {
        printf("Khong tim thay mat hang!\n");
        return;
    }

    for (i = viTri; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }

    n--;

    printf("Xoa thanh cong!\n");
}

void timMatHang() {
    char ten[50];
    int i;
    int timThay = 0;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("Nhap ten mat hang can tim: ");
    nhapTen(ten);

    for (i = 0; i < n; i++) {

        if (strcmp(ds[i].tenHang, ten) == 0) {

            if (timThay == 0) {
                inTieuDe();
            }

            inMotMatHang(ds[i]);
            timThay = 1;
        }
    }

    if (timThay == 0) {
        printf("Khong tim thay mat hang!\n");
    }
}

void thongKeKhoHang() {
    float tongGiaTri = 0;
    float thanhTien;
    float maxThanhTien;

    int demSapHet = 0;
    int viTriMax = 0;
    int i;

    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    maxThanhTien = ds[0].soLuong * ds[0].donGia;

    for (i = 0; i < n; i++) {

        thanhTien = ds[i].soLuong * ds[i].donGia;

        tongGiaTri = tongGiaTri + thanhTien;

        if (ds[i].soLuong < 5) {
            demSapHet++;
        }

        if (thanhTien > maxThanhTien) {
            maxThanhTien = thanhTien;
            viTriMax = i;
        }
    }

    printf("\n===== THONG KE KHO HANG =====\n");

    printf("Tong gia tri kho: %.0f dong\n", tongGiaTri);

    printf("\nDanh sach mat hang sap het (so luong < 5):\n");

    if (demSapHet == 0) {
        printf("Khong co mat hang sap het!\n");
    } else {

        inTieuDe();

        for (i = 0; i < n; i++) {
            if (ds[i].soLuong < 5) {
                inMotMatHang(ds[i]);
            }
        }
    }

    printf("\nSo mat hang sap het: %d\n", demSapHet);

    printf("\nMat hang co thanh tien lon nhat:\n");

    inTieuDe();
    inMotMatHang(ds[viTriMax]);
}

int main() {
    int chon;

    do {
        printf("\n========== QUAN LY MAT HANG ==========\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");

        printf("======================================\n");
        printf("Chon chuc nang: ");

        if (scanf("%d", &chon) != 1) {
            printf("Vui long nhap so!\n");
            xoaBoDem();
            continue;
        }

        xoaBoDem();

        switch (chon) {

            case 1:
                themMatHang();
                break;

            case 2:
                hienThiDanhSach();
                break;

            case 3:
                capNhatMatHang();
                break;

            case 4:
                xoaMatHang();
                break;

            case 5:
                timMatHang();
                break;

            case 6:
                thongKeKhoHang();
                break;

            case 0:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}

