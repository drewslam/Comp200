#include <iostream>

NASCARDriver::NASCARDriver() {
    RacecarDriver::SetName('none');
    RacecarDriver::SetWins(0);
}

NASCARDriver::NASCARDriver(std::string name, int wins, int ssWins);

void NASCARDriver::SetSSWins(int ssWins);

int NASCARDriver::GetSSWins() const;

void NASCARDriver::Print() const;

int ssWins;
