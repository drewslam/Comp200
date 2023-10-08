#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle operator*(Rectangle& a, Rectangle& b) {
    Rectangle newRect;
    newRect.setLength(a.getLength() + b.getLength());
    newRect.setWidth(a.getWidth() + b.getWidth());
    return newRect;
}

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
    for (int i = 0; i < 4; i += 2) {
        Rectangle NewRoom;
        NewRoom = House[i] * House[i + 1];
        totalArea += NewRoom.getArea();
    }
    cout << totalArea << endl;

    return 0;
}
