#include <iostream>

using namespace std;

class Ship {
public:
    Ship() { this->shipName = "none"; this->yearBuilt = 0; } ;
    Ship(string name, int year) { this->shipName = name; this->yearBuilt = year; };
    void SetName(string name) { this->shipName = name; };
    void SetYear(int year) { this->yearBuilt = year; };
    string GetName() const { return this->shipName; };
    int GetYear() const { return this->yearBuilt; };
    virtual void Print() const {
        cout << "Ship Info: " << endl;
        cout << "   Name: " << GetName() << endl;
        cout << "   Year Built: " << GetYear() << endl;
    };
private:
    string shipName;
    int yearBuilt;
};

class CruiseShip : public Ship {
public:
    CruiseShip() { this->peopleCapacity = 0; };
    CruiseShip(int people) { this->peopleCapacity = people; };
    void SetPeopleCapacity(int people) { this->peopleCapacity = people; }
    int GetPeopleCapacity() const { return this->peopleCapacity; }
    virtual void Print() const override {
        Ship::Print();
        cout << "   Can Hold " << GetPeopleCapacity() << " People"<< endl;
    }
private:
    int peopleCapacity;
};

class CargoShip : public Ship {
public:
    CargoShip() { this->storageCapacityInTons = 0; };
    CargoShip(int tons) { this->storageCapacityInTons = tons; };
    void SetStorageCapacity(int tons) { this->storageCapacityInTons = tons; };
    int GetStorageCapacity() const { return this->storageCapacityInTons; };
    virtual void Print() const override {
        Ship::Print();
        cout << "   Storage Capacity: " << GetStorageCapacity() << " Tons" << endl;
    }
private:
    int storageCapacityInTons;
};

int main() {
    int numShips;
    char userInput;
    string name;
    int year;
    int capacity;
    int i = 0;

    cout << "Input the number of ships: ";
    cin >> numShips;

    Ship** fleet = new Ship*[numShips];

    while (i < numShips) {
        cout << "Input A to add a Basic Ship | B to add a Cruise Ship | C to add a Cargo Ship" << endl;
        cin >> userInput;
        cin.ignore();
        if (userInput == 'A') {
            cout << "BASIC SHIP" << endl;
            cout << "Input the Name of your ship" << endl;
            getline(cin, name);
            cout << "Input the Year your ship was built" << endl;
            cin >> year;
            Ship* newShip = new Ship(name, year);
            fleet[i] = newShip;
            i++;
        } else if (userInput == 'B') {
            cout << "CRUISE SHIP" << endl;
            cout << "Input the Name of your ship" << endl;
            getline(cin, name);
            cout << "Input the Year your ship was built" << endl;
            cin >> year;
            cout << "Input the maximum person capacity" << endl;
            cin >> capacity;
            CruiseShip* newShip = new CruiseShip(capacity);
            newShip->SetName(name);
            newShip->SetYear(year);
            fleet[i] = newShip;
            i++;
        } else if (userInput == 'C') {
            cout << "CARGO SHIP" << endl;
            cout << "Input the Name of your ship" << endl;
            getline(cin, name);
            cout << "Input the Year your ship was built" << endl;
            cin >> year;
            cout << "Input the maximum storage capacity" << endl;
            cin >> capacity;
            CargoShip* newShip = new CargoShip(capacity);
            newShip->SetName(name);
            newShip->SetYear(year);
            fleet[i] = newShip;
            i++;
        }
    }

    for (int i = 0; i < numShips; i++) {
        fleet[i]->Print();
    }

    delete[] fleet;

    return 0;
}
