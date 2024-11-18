#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double xMax1, xMin1, yMax1, yMin1;
    double xMax2, xMin2, yMax2, yMin2;

    cin >> xMax1 >> xMin1 >> yMax1 >> yMin1;
    cin >> xMax2 >> xMin2 >> yMax2 >> yMin2;

    double dientich1 = (xMax1 - xMin1) * (yMax1 - yMin1);
    double dientich2 = (xMax2 - xMin2) * (yMax2 - yMin2);

    double tongdientich = dientich1 + dientich2;
    double hieudientich = fabs(dientich1 - dientich2);

      const double PI = 3.14;
    double bankinh1 = sqrt(tongdientich / PI);
    double bankinh2 = sqrt(hieudientich / PI);

    cout << dientich1 << " " << dientich2 << endl;
    cout << bankinh1 << endl;
    cout << bankinh2 << endl;

    return 0;
}
