#include <iostream>
#include <vector>
#include "RacecarDrivers.h"
#include "Formula1Driver.h"
using namespace std;

int main() {
    int numDrivers;
    cout << "Enter the number of drivers: ";
    cin >> numDrivers;
    RacecarDriver** driver_list = new RacecarDriver*[numDrivers];
    
    char userSelect;
    string name;
    int wins;
    int podiums;
    int i = 0;

    while (i < numDrivers) {
        while (userSelect != 'F' && userSelect != 'f' && userSelect != 'R' && userSelect != 'r') {
            cout << "Enter F for Formula 1 or R for Generic Racecar Driver" << endl;
            cin >> userSelect;
        }
    
        cin.ignore();
        if (userSelect == 'R' || userSelect == 'r') {
            cout << "Name" << endl;
            getline(cin, name);
            cout << "Wins" << endl;
            cin >> wins;
            RacecarDriver* racecarDriver = new RacecarDriver(name, wins);
            driver_list[i] = racecarDriver;
            i++;
        } else if (userSelect == 'F' || userSelect == 'f') {
            cout << "Name" << endl;
            getline(cin, name);
            cout << "Wins" << endl;
            cin >> wins;
            cout << "Podiums" << endl;
            cin >> podiums;
            Formula1Driver* formula1Driver = new Formula1Driver(name, wins, podiums);
            driver_list[i] = formula1Driver;
            i++;
        }
        userSelect = 'x';
    }

    for (int i = 0; i < numDrivers; i++) {
        driver_list[i]->Print();
    }
    
    delete[] driver_list;

    return 0;
}
