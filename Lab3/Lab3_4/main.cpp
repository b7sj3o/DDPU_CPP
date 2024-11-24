#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double x;
	double y;
	double R;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;

	bool A = pow((x + R), 2) + pow((y - R), 2) <= pow(R, 2);
	bool B = y >= 0 && y >= -R && x >= 0 && x <= R;

    // 1 - true
    // 0 - false    
    cout << (A || B) << endl;
	return 0;
}