#include <iostream>
using namespace std;

int main() {
    int soGa;
    cout << "Nhap so luong ga: ";
    cin >> soGa;

    double khoiLuong[soGa];
    int loaiGa[soGa];
    double tongKhoiLuongGaTrong = 0, tongKhoiLuongGaMai = 0;
    int soGaTrong = 0, soGaMai = 0;

    for (int i = 0; i < soGa; i++) {
        cout << "Nhap khoi luong cua con ga thu " << i + 1 << ": ";
        cin >> khoiLuong[i];
    }

    for (int i = 0; i < soGa; i++) {
        cout << "Nhap loai cua con ga thu " << i + 1 << " (0: Ga mai, 1: Ga trong): ";
        cin >> loaiGa[i];

        if (loaiGa[i] == 1) {
            tongKhoiLuongGaTrong += khoiLuong[i];
            soGaTrong++;
        } else if (loaiGa[i] == 0) {
            tongKhoiLuongGaMai += khoiLuong[i];
            soGaMai++;
        }
    }

    double trungBinhGaTrong;
    if (soGaTrong > 0) {
        trungBinhGaTrong = tongKhoiLuongGaTrong / soGaTrong;
    } else {
        trungBinhGaTrong = 0;
    }

    double trungBinhGaMai;
    if (soGaMai > 0) {
        trungBinhGaMai = tongKhoiLuongGaMai / soGaMai;
    } else {
        trungBinhGaMai = 0;
    }

    cout << "Khoi luong trung binh cua ga trong: " << trungBinhGaTrong << endl;
    cout << "Khoi luong trung binh cua ga mai: " << trungBinhGaMai << endl;

    int soGaMaiVuotTrungBinhGaTrong = 0;
    for (int i = 0; i < soGa; i++) {
        if (loaiGa[i] == 0 && khoiLuong[i] > trungBinhGaTrong) {
            soGaMaiVuotTrungBinhGaTrong++;
        }
    }

    cout << "So luong ga mai co khoi luong vuot trung binh ga trong: " << soGaMaiVuotTrungBinhGaTrong << endl;

    return 0;
}
