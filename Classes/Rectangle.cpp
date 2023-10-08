#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() {
    this->width = 0;
    this->length = 0;
}

Rectangle::Rectangle(int w, int l) {
    setWidth(w);
    setLength(l);
}

void Rectangle::setWidth(int w) {
    if (w > 0) {
        this->width = w;
    } else {
        cout << "Enter a positive width please: ";
        cin >> w;
        setWidth(w);
    }
}

void Rectangle::setLength(int l) {
    if (l > 0) {
        this->length = l;
    } else {
        cout << "Enter a positive length please: ";
        cin >> l;
        setLength(l);
    }
}

int Rectangle::getWidth() const {
    return this->width;
}

int Rectangle::getLength() const {
    return this->length;
}

int Rectangle::getArea() const {
    return this->width * this->length;
}

int Rectangle::getPerimeter() const {
    return (2 * this->width) + (2 * this->length);
}

void Rectangle::print() const {
    cout << "Width: " << getWidth() << endl;
    cout << "Length: " << getLength() << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}

int Rectangle::add(Rectangle& rect2) {
    Rectangle newRect;

    newRect.width = this->width + rect2.getWidth();
    newRect.length = this->length + rect2.getLength();

    return newRect.getArea();
}

Rectangle Rectangle::operator+ (const Rectangle& rect2) {
    Rectangle newRect;

    newRect.width = this->width + rect2.getWidth();
    newRect.length = this->length + rect2.getLength();

    return newRect;
}
