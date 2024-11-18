#include <iostream>
#include <string>
using namespace std;

struct Truong {
    string name;
    int ss;
    int gv;
    int r;
};

int main() {
    int soTruong;
    cout << "Nhap so truong: ";
    cin >> soTruong;

    Truong truong[soTruong];

    for (int i = 0; i < soTruong; i++) {
        cout << "Nhap ten truong thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, truong[i].name);
        cout << "Nhap si so cua truong: ";
        cin >> truong[i].ss;
        cout << "Nhap so giao vien cua truong: ";
        cin >> truong[i].gv;
        cout << "Nhap so phong hoc cua truong: ";
        cin >> truong[i].r;
    }

    double tiLeHsGvCaoNhat = 0;
    int phongNhieuNhat = 0;
    int soHsTrongMotLopItNhat = INT_MAX;

    for (int i = 0; i < soTruong; i++) {
        if (truong[i].gv > 0) {
            double tiLe = (double)truong[i].ss / truong[i].gv;
            if (tiLe > tiLeHsGvCaoNhat) {
                tiLeHsGvCaoNhat = tiLe;
            }
        }
        if (truong[i].r > phongNhieuNhat) {
            phongNhieuNhat = truong[i].r;
        }
        if (truong[i].r > 0) {
            int hsTrongMotLop = truong[i].ss / truong[i].r;
            if (hsTrongMotLop < soHsTrongMotLopItNhat) {
                soHsTrongMotLopItNhat = hsTrongMotLop;
            }
        }
    }

    cout << "Ti le hs/gv cao nhat: " << tiLeHsGvCaoNhat << endl;
    cout << "So phong nhieu nhat: " << phongNhieuNhat << endl;
    cout << "So hs trong mot lop it nhat: " << soHsTrongMotLopItNhat << endl;

    return 0;
}
