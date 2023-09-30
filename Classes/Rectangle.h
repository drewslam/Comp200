#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    public:
        Rectangle();
        Rectangle(int w, int l);
        void setWidth(int w);
        void setLength(int l);
        int getWidth() const;
        int getLength() const;
        int getArea() const;
        int getPerimeter() const;
        void print() const;
    private:
        int width;
        int length;
};

#endif // RECTANGLE_H
