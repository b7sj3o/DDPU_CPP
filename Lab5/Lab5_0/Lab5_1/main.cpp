#include <iostream>
#include <cmath>

using namespace std;

double squared_nums(const double x, const double y, const double c);

int main()
{
	double x, y;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	double part1 = squared_nums(x * y, pow(x, 2), pow(y, 2));
    double part2 = squared_nums(1, x, y);
    double part3 = squared_nums(sqrt(x), pow(y, 2), 1);

    double result = (part1 - pow(part2, 2)) / 1 + part3;

	cout << "result = " << result << endl;
	return 0;
}

double squared_nums(const double a, const double b, const double c)
{
	return pow(a,2) + pow(b, 2) + pow(c, 2);
}