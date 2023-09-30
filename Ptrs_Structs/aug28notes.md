`     /* 1) create a pointer which points to an int. have it point to another int.
    then after that change the values of the int using only the pointer */
    /* int a = 5;
    int* a_ptr = &a;
    int b = 6;

    cout << "a: " << a << " b: " << b << " a_ptr: " << a_ptr << endl;

    a_ptr = &b;

    cout << "a: " << a << " b: " << b << " a_ptr: " << a_ptr << endl;

    a_ptr += 7;

    cout << "a: " << a << " b: " << b << " a_ptr: " << a_ptr << endl; */
`

`
// Create an array and point to every other number, use pointers
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr = arr;


    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            cout << *(ptr + i) << " ";
        }
    }
`
