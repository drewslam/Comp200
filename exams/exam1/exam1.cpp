/// Andrew Souza
/// Comp 200 -- Fall 2023
/// Exam 1
#include <iostream>

using namespace std;


// In resize, you are to ask the user how many elements (i.e. spaces) they would like to add to the array.
int* resize(int* input, int& size) {
    int addSize;
    cout << "How many more spaces would you like to add to this array?" << endl;
    cin >> addSize;
    int* resizedArr = new int[size + addSize];

    for (int i = 0; i < size; i++) {
        *(resizedArr + i) = *(input + i);
    }

    size += addSize;

    return resizedArr;
}

int main() {
    int size = 5;
    int userArr[size]; // Starting array initialized with 5 values
    int userInput = -1;
    int index = 0;
    int count = 0;  // Counter for each value added to array

    cout << "Please enter a series of integers (enter -1 to exit)" << endl;
    cin >> userInput;

    int* inputPtr = &userInput;
    while (userInput != -1) {
      *(userArr + index) = inputPtr;
        count++;
        index++;
        if (count == size) {
            *userArr = resize(*userArr, size);
        }
        cin >> userInput;
    }

    cout << "success" << endl;

    // When the user finally enters a -1, you are to print the elements of the array.
    for (int i = 0; i < size; i++) {
        cout << *userArr[i] << " ";
    }
    cout << endl;

    for (int i = 5; i < size; i++) {
        delete userArr[i];
    }

    return 0;
}
