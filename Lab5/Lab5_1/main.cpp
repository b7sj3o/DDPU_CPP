#include <iostream>
#include <cmath>

using namespace std;

double squared_nums(const double x, const double y, const double c);

int main()
{
	double x, y;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	double result = (squared_nums(x * y, pow(x, 2), pow(y, 2)) - pow(squared_nums(1, x, y), 2)) / 1 + squared_nums(sqrt(x), pow(y, 2), 1);
	cout << "result = " << result << endl;
	return 0;
}

double squared_nums(const double a, const double b, const double c)
{
	return pow(a,2) + pow(b, 2) + pow(c, 2);
}