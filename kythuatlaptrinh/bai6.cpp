#include <iostream>
using namespace std;

int main() {
    int soPhong;
    cout << "Nhap so phong hoc: ";
    cin >> soPhong;

    double dienTich[soPhong];
    double tongDienTich = 0;

    for (int i = 0; i < soPhong; i++) {
        cout << "Nhap dien tich phong thu " << i + 1 << ": ";
        cin >> dienTich[i];
        tongDienTich += dienTich[i];
    }

    double trungBinh = tongDienTich / soPhong;
    int soPhongItHonTrungBinh = 0;

    for (int i = 0; i < soPhong; i++) {
        if (dienTich[i] < trungBinh) {
            soPhongItHonTrungBinh++;
        }
    }

    cout << "So phong co dien tich it hon trung binh: " << soPhongItHonTrungBinh << endl;
    return 0;
}
