#ifndef FORMULA_1_DRIVER
#define FORMULA_1_DRIVER

#include "RacecarDrivers.h"

class Formula1Driver : public RacecarDriver {
    public:
        Formula1Driver();
        Formula1Driver(std::string name, int wins, int podiums);
        void SetPodiums(int podiums);
        int GetPodiums() const;
        virtual void Print() const override;
    private:
        int racePodiums;
};

#endif
