#include <iostream>
#include <string>
#include <vector>
using namespace std;

// automobile class, derived car class, derived motorcycle class
// Auto: Print, miles, date, make, model - all accessor/matutors
class Automobile {
public:
    void SetMilesDriven(int miles);
    void SetModelYear(int year);
    void SetMake(string make);
    void SetModel(string model);
    int GetMilesDriven() const;
    int GetModelYear() const;
    string GetMake() const;
    string GetModel() const;
    void PrintInfo() const;
private:
    int milesDriven;
    int modelYear;
    string make;
    string model;
};

// derived classes - tire wear per wheel, number of doors, seats, speed
/* Please also add additional functions/information to the derived classes,
 * such that they become different */
class Car : public Automobile {
public:
    void SetNumberOfDoors(int doors);
    void SetTireWearPerWheel();
    void SetNumberOfSeats(int seats);
    void SetSpeed(int speed);
    void SetColor(int color);
    int GetNumberOfDoor() const;
    int* GetTireWearPerWheel();
    int GetNumberOfSeats() const;
    int GetSpeed() const;
    string GetColor() const;

private:
    int numberOfDoors;
    int* tireWearPerWheel[4];
    int numberOfSeats;
    int speed;
    string color;
};

class Motorcycle : public Automobile {
public:
    void SetNumberOfWheels(int wheels);
    void SetPersonCapacity(int people);
    void SetSpeed(int speed);
    int GetNumberOfWheels() const;
    int GetPersonCapacity() const;
    int GetSpeed() const;
    void PrintInfo() const;
private:
    int numberOfWheels;
    int personCapacity;
    int speed;
};

void Automobile::SetMake(string make) {
    this->make = make;
}

void Automobile::SetModelYear(int year) {
    this->modelYear = year;
}

void Automobile::SetModel(string model) {
    this->model = model;
}

void Automobile::SetMilesDriven(int miles) {
    this->milesDriven = miles;
}

string Automobile::GetMake() const {
    return this->make;
}

int Automobile::GetModelYear() const {
    return this->modelYear;
}

string Automobile::GetModel() const {
    return this->model;
}

int Automobile::GetMilesDriven() const {
    return this->milesDriven;
}

void Automobile::PrintInfo() const {
    cout << "Make: " << GetMake() << endl;
    cout << "Model Year: " << GetModelYear() << endl;
    cout << "Model: " << GetModel() << endl;
    cout << "Miles Driven: " << GetMilesDriven() << endl;
}

void Car::SetNumberOfDoors(int doors) {
    this->numberOfDoors = doors;
}

void Car::SetTireWearPerWheel() {
    for (int i = 0; i < 4; i++) {
        cout << "Enter tire wear for tire " << i + 1 << endl;
        int* temp = new int;
        cin >> *temp;
        *(this->tireWearPerWheel + i) = temp;
    }
}

void Car::SetNumberOfSeats(int seats) {
    this->numberOfSeats = seats;
}

void Car::SetSpeed(int speed) {
    this->speed = speed;
}

void Car::SetColor(int color) {
    this->color = color;
}

int Car::GetNumberOfDoor() const {
    return this->numberOfDoors;
}

int* Car::GetTireWearPerWheel() {
    return *this->tireWearPerWheel;
}

int Car::GetNumberOfSeats() const {
    return this->numberOfSeats;
}

int Car::GetSpeed() const {
    return this->speed;
}

string Car::GetColor() const {
    return this->color;
}

int main() {
    Car* myCar = nullptr;
    myCar->SetTireWearPerWheel();

    // myCar->PrintInfo();

    return 0;
}
