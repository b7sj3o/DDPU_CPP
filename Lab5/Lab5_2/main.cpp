#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double A(double x, int n, double prevTerm) {
	double term = pow(-1, n+1) / ( (2*n+1) * pow(x, 2*n+1));
    return term;
}

double S(double x, double eps, int &termCount) {
    double sum = -M_PI_2; 
    double term = -1 / x;
    termCount = 1;

    sum += term;

    while (fabs(term) > eps) {
        term = A(x, termCount, term);
        sum += term;
        termCount++;
    }

    return sum;
}

int main() {
    double x1, x2, dx, eps;

    // Введення параметрів
    cout << "x1 = "; cin >> x1;
    cout << "x2 = "; cin >> x2;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

	// header
    cout << setw(10) << "x" 
         << setw(20) << "arctg(x)" 
         << setw(20) << "Sum" 
         << setw(10) << "Terms" << endl;
    cout << string(60, '-') << endl;

    for (double x = x1; x <= x2; x += dx) {
        int termCount = 0; // Кількість членів ряду
        double seriesSum = S(x, eps, termCount);
        double trueValue = atan(x); // Реальне значення arctg(x)

        // Виведення результату
        cout << setw(10) << fixed << setprecision(4) << x 
             << setw(20) << trueValue 
             << setw(20) << seriesSum 
             << setw(10) << termCount << endl;
    }

    return 0;
}
