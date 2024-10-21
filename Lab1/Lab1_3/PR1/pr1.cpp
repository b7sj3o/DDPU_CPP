#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    int i = 1;
    int p = 1;

    while (i < 10) {
        p += i;
        i++;
    }

    cout << "p = " << p << ", i = " << i << endl;

    // 'pause' є лише в cmd, в sh нема цього, натомість:
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
