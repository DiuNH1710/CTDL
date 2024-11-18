

#include <iostream>
#include <string>
using namespace std;

int main() {
    string ten, giai_dau;
    int tuoi, so_ban_thang;
    double chieu_cao, can_nang;

    cin >> ten >> tuoi >> chieu_cao >> can_nang >> giai_dau >> so_ban_thang;

    double BMI = can_nang / (chieu_cao * chieu_cao);

    if (chieu_cao > 1.8 && so_ban_thang >= 10 && BMI >= 20 && BMI <= 24) {
        cout << "Worthy" << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}
