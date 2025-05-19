#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

bool isInsideTarget(double x, double y, double R) {
	// верхнє праве коло
    if (x <= 0 && y >= 0 && x * x + y * y <= R * R) {
        return true;
    }

    if (x >= 0 && y <= 0 && x * x + y * y <= R * R) {
        return true;
    }

    return false;
}

int main() {
    double x, y, R;

    srand(static_cast<unsigned>(time(NULL)));

    cout << "R = : "; cin >> R;

    // 1 спосіб
    cout << "Перший спосіб:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if (isInsideTarget(x, y, R)) {
            cout << "Зачіпило" << endl;
        } else {
            cout << "Не зачіпило" << endl;
        }
    }

    // 2 спосіб:
    cout << "Випадкові точки:" << endl;
    for (int i = 0; i < 10; i++) {
        x = 2 * R + rand() * (- 2 * R - 2 * R) / RAND_MAX;
		y = 2 * R + rand() * (-2 * R - 2 * R) / RAND_MAX;

        cout << fixed << setprecision(4) << "Point (" << x << ", " << y << "): ";
        if (isInsideTarget(x, y, R)) {
            cout << "Зачіпило" << endl;
        } else {
            cout << "Не зачіпило" << endl;
        }
    }

    return 0;
}

