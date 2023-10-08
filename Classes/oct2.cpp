#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle* operator*(Rectangle& a, Rectangle& b) {
    Rectangle* newRect = new Rectangle;
    newRect->setLength(a.getLength() + b.getLength());
    newRect->setWidth(a.getWidth() + b.getWidth());
    return newRect;
}

int main() {
    Rectangle* rect1 = new Rectangle(5, 3);
    Rectangle* rect2 = new Rectangle(6, 4);
    Rectangle* newRect = rect1 * rect2;
    cout << rect1->getArea() << " " << rect2->getArea() << endl;
    cout << newRect->getArea() << endl;
    
    delete rect1;
    delete rect2;
    delete newRect;

    return 0;
}
