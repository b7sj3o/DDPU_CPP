#include <iostream>
#include <cstring>

using namespace std;


void findThirdDotIterative(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.' && ++count == 3) {
            cout << "Found the third dot at index: " << i << endl;
            return;
        }
    }
    cout << "Third dot not found." << endl;
}

int findThirdDotRecursive(const char* str, int index = 0, int count = 0) {
    if (str[index] == '\0') return -1;
    if (str[index] == '.' && ++count == 3) return index;
    return findThirdDotRecursive(str, index + 1, count);
}

int findThirdDotSTL(const string& s) {
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '.' && ++count == 3)
            return i;
    }
    return -1;
}

int findThirdDotWhile(const char* str) {
    int i = 0, count = 0;
    while (str[i] != '\0') {
        if (str[i] == '.' && ++count == 3)
            return i;
        ++i;
    }
    return -1;
}


int main() {
    char myStr[100];
    cin >> myStr;
    
    cout << "Iterative method: ";
    findThirdDotIterative(myStr);

    cout << "Recursive method: ";
    int index = findThirdDotRecursive(myStr);
    if (index != -1) {
        cout << "Found the third dot at index: " << index << endl;
    } else {
        cout << "Third dot not found." << endl;
    }

    cout << "STL method: ";
    string str(myStr);
    int stlIndex = findThirdDotSTL(str);
    if (stlIndex != -1) {
        cout << "Found the third dot at index: " << stlIndex << endl;
    } else {
        cout << "Third dot not found." << endl;
    }

    cout << "While loop method: ";
    int whileIndex = findThirdDotWhile(myStr);
    if (whileIndex != -1) {
        cout << "Found the third dot at index: " << whileIndex << endl;
    } else {
        cout << "Third dot not found." << endl;
    }

    return 0;
}