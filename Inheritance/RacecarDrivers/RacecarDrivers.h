#ifndef RACECARDRIVERS_H
#define RACECARDRIVERS_H

#include <iostream>
using namespace std;

class RacecarDriver {
    public:
        RacecarDriver();
        RacecarDriver(string name, int wins);
        void SetDriverName(string name);
        void SetRaceWins(int wins);
        string GetDriverName() const;
        int GetRaceWins() const;
        virtual void Print() const;
    private:
        string driverName;
        int raceWins;
};

#endif
