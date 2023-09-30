#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    Rectangle newRect;
    int width;
    int length;

    cout << "Enter the length and width of your rectangle" << endl;
    cin >> length >> width;
    newRect.setLength(length);
    newRect.setWidth(width);
    newRect.print();
    return 0;
}
