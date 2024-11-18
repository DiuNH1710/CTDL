#include <iostream>
using namespace std;

int main() {
    int N, tong_tuoi = 0, so_clb_tren_30 = 0, so_clb_duoi_23 = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int so_cau_thu, tuoi_tb;
        cin >> so_cau_thu >> tuoi_tb;
        tong_tuoi += tuoi_tb;

        if (so_cau_thu > 30) {
            so_clb_tren_30 += 1;
        }

        if (tuoi_tb < 23) {
            so_clb_duoi_23 += 1;
        }
    }

    cout << "Do tuoi trung binh cua tat ca cac cau lac bo: " << (tong_tuoi / N) << endl;
    cout << "So cau lac bo co tren 30 cau thu dang ky: " << so_clb_tren_30 << endl;
    cout << "So cau lac bo co do tuoi trung binh duoi 23: " << so_clb_duoi_23 << endl;

    return 0;
}
