#include <iostream>
#include <string>
using namespace std;

class SinhVien {
public:
    int maSV;
    string ten;
    string lop;
    SinhVien* tiepTheo;

    // Constructor
    SinhVien(int id, string hoTen, string lopHoc) {
        maSV = id;
        ten = hoTen;
        lop = lopHoc;
        tiepTheo = nullptr;
    }
};

// Hàm thêm sinh viên vào danh sách
void themSinhVien(SinhVien*& danhSach, int id, string hoTen, string lopHoc) {
    SinhVien* moi = new SinhVien(id, hoTen, lopHoc);
    if (danhSach == nullptr) {
        danhSach = moi;
    } else {
        SinhVien* tam = danhSach;
        while (tam->tiepTheo != nullptr) {
            tam = tam->tiepTheo;
        }
        tam->tiepTheo = moi;
    }
}

// Hàm xóa sinh viên theo mã ID
void xoaSinhVien(SinhVien*& danhSach, int id) {
    if (danhSach == nullptr) return;

    if (danhSach->maSV == id) {
        SinhVien* xoa = danhSach;
        danhSach = danhSach->tiepTheo;
        delete xoa;
        return;
    }

    SinhVien* truoc = danhSach;
    SinhVien* hienTai = danhSach->tiepTheo;

    while (hienTai != nullptr) {
        if (hienTai->maSV == id) {
            truoc->tiepTheo = hienTai->tiepTheo;
            delete hienTai;
            return;
        }
        truoc = hienTai;
        hienTai = hienTai->tiepTheo;
    }
}

// Hàm tìm và hiển thị thông tin sinh viên
void timSinhVien(SinhVien* danhSach, int id) {
    SinhVien* tam = danhSach;
    while (tam != nullptr) {
        if (tam->maSV == id) {
            cout << "ID: " << tam->maSV << endl;
            cout << "Ten: " << tam->ten << endl;
            cout << "Lop: " << tam->lop << endl;
            return;
        }
        tam = tam->tiepTheo;
    }
    cout << "NA,NA" << endl;
}

int main() {
    SinhVien* danhSachSinhVien = nullptr;

    while (true) {
        int luaChon;
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Xoa sinh vien" << endl;
        cout << "3. Tim sinh vien" << endl;
        cout << "4. Thoat" << endl;
        cout << "==========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            int id;
            string ten, lop;
            cout << "Nhap ID: ";
            cin >> id;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << "Nhap lop: ";
            cin >> lop;
            themSinhVien(danhSachSinhVien, id, ten, lop);
        } else if (luaChon == 2) {
            int id;
            cout << "Nhap ID can xoa: ";
            cin >> id;
            xoaSinhVien(danhSachSinhVien, id);
        } else if (luaChon == 3) {
            int id;
            cout << "Nhap ID can tim: ";
            cin >> id;
            timSinhVien(danhSachSinhVien, id);
        } else {
            cout << "Thoat chuong trinh." << endl;
            break;
        }
    }

    return 0;
}
