#include <iostream>

using namespace std;

int NCD(int n, int m) {
    if (m == 0) {
        return n;
    }
    return NCD(m, n % m);
}

int main() {
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    cout << "GCD(" << n << ", " << m << ") = " << NCD(n, m) << endl;
    return 0;
}
