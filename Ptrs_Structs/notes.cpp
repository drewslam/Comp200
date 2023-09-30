#include <iostream>
#include <iomanip>
using namespace std;

int main() {
/*    int* counts[10];
    int i, j;
    for (i = 0; i < 10; i++) {
        counts[i] = new int[i + 1];
    }

    for (j = 0; j <= i; j++) {
        cout << setw(4) << counts[i][j];
    }
    cout << endl; */
    double a = 1000; // 20300
    double b = 2000; // 20308
    double* p = &a;  // p = 1000
    double* q = &b;  // q = 2000
    *p = *q;         // p = q = 2000
    p = q;           // p = 2000
    *p = 3000;
    cout << a << endl;
    return 0;
}

