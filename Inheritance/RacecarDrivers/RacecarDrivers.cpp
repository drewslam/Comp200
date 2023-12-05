#include <iostream>
#include "RacecarDrivers.h"

RacecarDriver::RacecarDriver() {
    this->driverName = "none";
    this->raceWins = 0;
}

RacecarDriver::RacecarDriver(std::string name, int wins) {
    this->driverName = name;
    this->raceWins = wins;
}

void RacecarDriver::SetDriverName(std::string name) {
    this->driverName = name;
}

void RacecarDriver::SetRaceWins(int wins) {
    this->raceWins = wins;
}

std::string RacecarDriver::GetDriverName() const {
    return this->driverName;
}

int RacecarDriver::GetRaceWins() const {
    return this->raceWins;
}

void RacecarDriver::Print() const {
    std::cout << "Name: " << this->driverName << std::endl;
    std::cout << "Race Wins: " << this->raceWins << std::endl;
}
