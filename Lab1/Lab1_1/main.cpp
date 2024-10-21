#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int p = 1;
    int i = 1;
    cout << "Error" << endl;
    while (i <= 10)
    {
        p *= i;
        i++;
    };
    cout << "p = " << p << " i = " << i << endl;
    return 0;
}
