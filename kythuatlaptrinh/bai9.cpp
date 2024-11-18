#include <iostream>
using namespace std;

int main() {
    int xMin1, xMax1, yMin1, yMax1;
    int xMin2, xMax2, yMin2, yMax2;

    cout << "Nhap toa do hinh chu nhat 1 (xMin, xMax, yMin, yMax): ";
    cin >> xMin1 >> xMax1 >> yMin1 >> yMax1;

    cout << "Nhap toa do hinh chu nhat 2 (xMin, xMax, yMin, yMax): ";
    cin >> xMin2 >> xMax2 >> yMin2 >> yMax2;

    int xMinGiao = max(xMin1, xMin2);
    int xMaxGiao = min(xMax1, xMax2);
    int yMinGiao = max(yMin1, yMin2);
    int yMaxGiao = min(yMax1, yMax2);

    if (xMinGiao < xMaxGiao && yMinGiao < yMaxGiao) {
        int dienTichGiao = (xMaxGiao - xMinGiao) * (yMaxGiao - yMinGiao);
        cout << "Dien tich phan giao nhau: " << dienTichGiao << endl;
    } else {
        cout << "Hai hinh chu nhat khong giao nhau." << endl;
    }

    return 0;
}
