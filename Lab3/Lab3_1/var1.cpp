#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x;
    float y;
    
    cout << "x = "; cin >> x;
    
    y = pow(x, -3) + 1;

    if (x < 1) y -= 0.3 * x + 7;
    else if (x >= 1 && x <= 5.5) y -= atan((x+2.0) / 8.1) + exp(x);
    else y -= sqrt(1 + sqrt(1 + sqrt(x)));

    cout << "y = " << y << endl;

    y = pow(x, -3) + 1;

    if (x < 1) {
        y -= 0.3 * x + 7;
    } else if (x >= 1 && x <= 5.5) {
        y -= atan((x+2.0) / 8.1) + exp(x);
    } else {
        y -= sqrt(1 + sqrt(1 + sqrt(x)));
    }

    cout << "y = " << y << endl;

    return 0;
}

