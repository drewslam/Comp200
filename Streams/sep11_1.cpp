#include <iostream>

using namespace std;

/* I would like for you to take in an array of ints.  pass this to a function.
    ask the user how many more ints they would like to be added to the array along with adding those elements to the array.
    return the new array to main and print this out */
int* add(int* arr, int size, int add) {
    int* r = new int[size + add];
    for (int i = 0; i < size; i++) {
        *(r + i) = *(arr + i);
    }
    for (int i = size; i < size + add; i++) {
        cin >> *(r + i);
    }
    return r;
}

int main() {
    int arr[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int numsToAdd;
    int* result;
    cout << "How many more would you like to add?" << endl;
    cin >> numsToAdd;

    result = add(arr, 20, numsToAdd);

    for (int i = 0; i < 20 + numsToAdd; i++) {
        if ((i + 1) % 4 != 0) {
            cout << *(result + i) << "\t";
        } else {
            cout << *(result + i) << endl;
        }
    }
    cout << endl;

    delete[] result;

    return 0;
}
