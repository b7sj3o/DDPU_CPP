#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float R, x, y;
    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;

    if (x <= -6) {
        y = R;
    } else if (x > -6 && x <= -R) {
        y = (R + x) / (6 - R);
    } else if (x > -R && x <= 0) {
        y = R - sqrt(pow(R, 2) - pow((x+R), 2));
    } else if (x > 0 && x <= R) {
        y = sqrt(pow(R, 2) - pow(x, 2));
    } else {
        y = -x + R;
    }

    cout << "y = " << y << endl;
    
    return 0;
} 

