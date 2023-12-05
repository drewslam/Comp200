#include <iostream>
#include "RacecarDrivers.h"
#include "Formula1Driver.h"

Formula1Driver::Formula1Driver() {
    RacecarDriver::SetDriverName("none");
    RacecarDriver::SetRaceWins(0);
    this->racePodiums = 0;
}

Formula1Driver::Formula1Driver(std::string name, int wins, int podiums) {
    RacecarDriver::SetDriverName(name);
    RacecarDriver::SetRaceWins(wins);
    this->racePodiums = podiums;
}

void Formula1Driver::SetPodiums(int podiums) {
    this->racePodiums = podiums;
}

int Formula1Driver::GetPodiums() const {
    return this->racePodiums;
}

void Formula1Driver::Print() const {
    RacecarDriver::Print();
    std::cout << "Podiums: " << this->racePodiums << std::endl;
}

