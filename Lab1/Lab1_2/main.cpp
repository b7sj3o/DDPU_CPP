#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Hello, World!" << endl;
    cin >> a;
    int p = 1;
    int i = 1;
    while (i <= 10)
    {
        p *= i;
        i++;
    };
    cout << "p = " << p << "i = " << i << endl;
    system("pause");
    return 0;
}
