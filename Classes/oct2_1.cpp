#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    Rectangle House[4];
    int width = 1;
    int length = 1;
    int totalArea = 0;
    
    for (int i = 0; i < 4; i++) {
        cout << "Enter the length and width of room " << i + 1 << endl;
        cin >> length >> width;
        House[i].setLength(length);
        House[i].setWidth(width);
    }

    cout << "Total Area: ";
    for (int i = 0; i < 4; i++) {
        totalArea += House[i].getArea();
    }
    cout << totalArea << endl;
        
    return 0;
}
