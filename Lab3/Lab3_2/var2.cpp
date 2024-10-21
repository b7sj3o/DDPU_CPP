#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x, a, b, c, F;
    cout << "x = "; cin >> x;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    

    if (x < 0.6 && (b+c != 0)) {
        F  = a*(pow(x, 2)) + b*x + c;
    } else if (x > 0.6 && (b+c == 0)) {
         F = (x-a) / (x-c);
    } else {
        F = (x/c) + (x/a);
    } 

    cout << "F = " << F << endl;

    return 0;
}

