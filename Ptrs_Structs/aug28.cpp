#include <iostream>
using namespace std;

int* EvensArr(int* arr, int size, int sizeEvens) {
    int* evensArr = new int[sizeEvens];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            *(evensArr + j) = *(arr + i);
            j++;
        }
    }
    return evensArr;
}

int main() {
    // Ask user for size of array, dynamically allocate array, prompt user to fill in values
    // Print out every odd number
    // Min 20 numbers

    int size = 0;
    int evens = 0;
    while (size < 21) {
        cout << "Enter a number greater than 20: ";
        cin >> size;
    }

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        cin >> *(arr + i);
    }

    cout << "Odd numbers: ";
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            cout << *(arr + i) << " ";
        } else {
            evens++;
        }
    }
    cout << endl;

    cout << "Even numbers: ";
    int* evensArr = EvensArr(arr, size, evens);
    for (int i = 0; i < evens; i++) {
        cout << *(evensArr + i) << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] evensArr;

    return 0;
}
