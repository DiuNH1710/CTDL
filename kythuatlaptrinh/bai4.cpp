#include <iostream>
#include <string>
using namespace std;

int main() {
    string ten;
    char tiep_tuc;
    int so_cau_thu = 0, tong_so_ao = 0, so_ao = 0;

    while (true) {
        cin >> ten;
        if (ten == "E") break;

        while (true) {
            string input;
            cin >> input;

            if (input == "#") break;

            for (char c : input) {
                if (c >= '0' && c <= '9') {
                    so_ao = so_ao * 10 + (c - '0');
                }
            }
            tong_so_ao += so_ao;
            so_ao = 0;
        }

        so_cau_thu++;
        cin >> tiep_tuc;
        if (tiep_tuc == 'E') break;
    }

    if (so_cau_thu > 0) {
        cout << "So cau thu duoc phong van: " << so_cau_thu << endl;
        cout << "Trung binh so ao dau ưa thích: " << (double)tong_so_ao / so_cau_thu << endl;
    }

    return 0;
}