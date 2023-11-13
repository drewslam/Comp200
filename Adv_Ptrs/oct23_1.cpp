#include <iostream>

using namespace std;
// Vector Class
class vector {
private:
    int size;
    int* arr;
    int* ptr;
public:
    vector();
    vector(int size);
    void add(int newInt);
    void delete(int numToDel);
    void find(int test);
    int at(int position);
    void resize(int newSize);
};

vector::vector() {
    this->size = 0;
}

vector::vector(int size) {
    this->size = size;
}

void vector::add(int newInt) {

}

void vector::delete(int newInt);

void vector::find(int test);

int vector::at(int position) {
    if (position < this->size && position >= 0) {
        return this->*(arr + position);
    }
}

void vector::resize(int newSize) {
    this->size += newSize;
}


int main() {

    return 0;
}
