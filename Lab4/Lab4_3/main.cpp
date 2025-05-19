#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x, a, c, b, xp, xk, dx, F;

    cout << "a = "; cin >> a;
    cout << "c = "; cin >> c;
    cout << "b = "; cin >> b;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "----------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "F" << " |" << endl;
    cout << "----------------------" << endl;

    x = xp;

    while (x <= xk) {
        if (x < 5 && c != 0) {
            F = -a * pow(x, 2) - b;
        }
        else if (x > 5 && c == 0) {
            F = (x - a) / x;
        }
        else {
            F = -x / c;
        }

        cout << "|" << setw(7) << setprecision(2) << x
             << " |" << setw(10) << setprecision(3) << F
             << " |" << endl;

        x += dx;
    }
    cout << "----------------------" << endl;

    return 0;
}
