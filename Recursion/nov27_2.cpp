#include <iostream>
#include <cstring>
using namespace std;

// Recursively print a c string in reverse

void Reverse(char* str, int index) {
    if (str[index] == '\0') {
        return;
    }
    Reverse(str, index + 1);
    cout << str[index];
}

int main() {
    char str[] = "hello";
    Reverse(str, 0);
    cout << endl;

    return 0;
}
