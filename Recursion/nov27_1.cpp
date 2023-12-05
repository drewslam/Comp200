#include <iostream>

using namespace std;

// Recursively find the factorial of a number

int Factorial(int n) {
    int factorial;
    if (n == 1 || n == 0) {
        return 1;
    } else {
        factorial = n * Factorial(n - 1);
    }
    return factorial;
}

int main() {
    int n;

    cout << "Enter a number value: ";
    cin >> n;

    cout << Factorial(n) << endl;

    return 0;
}
