#include <iostream>
#include <string>

using namespace std;

struct ThanhPho {
    string ten;
    double mucDoHaiLong;
    string thanhPhoDangSong[3];
};

int main() {
    int n;
    cin >> n;

    ThanhPho danhSach[100];
    string tatCaThanhPho[300];
    int demSoLanNhacDen[300] = {0};
    int tongSoThanhPho = 0;

    for (int i = 0; i < n; i++) {
        cin >> danhSach[i].ten >> danhSach[i].mucDoHaiLong;
        for (int j = 0; j < 3; j++) {
            cin >> danhSach[i].thanhPhoDangSong[j];
            bool daCo = false;
            for (int k = 0; k < tongSoThanhPho; k++) {
                if (tatCaThanhPho[k] == danhSach[i].thanhPhoDangSong[j]) {
                    demSoLanNhacDen[k]++;
                    daCo = true;
                    break;
                }
            }
            if (!daCo) {
                tatCaThanhPho[tongSoThanhPho] = danhSach[i].thanhPhoDangSong[j];
                demSoLanNhacDen[tongSoThanhPho]++;
                tongSoThanhPho++;
            }
        }
    }

    double mucHaiLongThapNhat = danhSach[0].mucDoHaiLong;
    for (int i = 1; i < n; i++) {
        if (danhSach[i].mucDoHaiLong < mucHaiLongThapNhat) {
            mucHaiLongThapNhat = danhSach[i].mucDoHaiLong;
        }
    }

    int soThanhPhoHaiLongThapNhat = 0;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].mucDoHaiLong == mucHaiLongThapNhat) {
            soThanhPhoHaiLongThapNhat++;
        }
    }

    if (soThanhPhoHaiLongThapNhat == 1) {
        for (int i = 0; i < n; i++) {
            if (danhSach[i].mucDoHaiLong == mucHaiLongThapNhat) {
                cout << danhSach[i].ten << endl;
                break;
            }
        }
    } else {
        cout << soThanhPhoHaiLongThapNhat << endl;
    }

    int soLanNhacDenNhieuNhat = 0;
    for (int i = 0; i < tongSoThanhPho; i++) {
        if (demSoLanNhacDen[i] > soLanNhacDenNhieuNhat) {
            soLanNhacDenNhieuNhat = demSoLanNhacDen[i];
        }
    }

    int soThanhPhoDuocNhacDenNhieuNhat = 0;
    for (int i = 0; i < tongSoThanhPho; i++) {
        if (demSoLanNhacDen[i] == soLanNhacDenNhieuNhat) {
            soThanhPhoDuocNhacDenNhieuNhat++;
        }
    }

    if (soThanhPhoDuocNhacDenNhieuNhat == 1) {
        for (int i = 0; i < tongSoThanhPho; i++) {
            if (demSoLanNhacDen[i] == soLanNhacDenNhieuNhat) {
                cout << tatCaThanhPho[i] << endl;
                break;
            }
        }
    } else {
        cout << soThanhPhoDuocNhacDenNhieuNhat << endl;
    }

    return 0;
}
