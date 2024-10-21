// Lab_02.cpp
// Федитник Віталій
// Лабораторна робота № 2.1
// Лінійні програми.
// Варіант 32
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double A; // вхідний параметр
    double z1; // результат обчислення 1-го виразу
    double z2; // результат обчислення 2-го виразу
    cout << "A = "; cin >> A;
    z1 = (sin(4 * A) / (1 + cos(4 * A))) * (cos(2 * A) / (1 + cos(2 * A)));
    z2 = 1 / tan((3.0 / 2.0) * M_PI - A);

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    
    cin.get();
    
    return 0;
}