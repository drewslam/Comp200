#ifndef NASCAR_DRIVER
#define NASCAR_DRIVER

#include "RacecarDrivers.h"

class NASCARDriver : public RacecarDriver {
    public:
        NASCARDriver();
        NASCAR::Driver(std::string name, int wins, int ssWins);
        void SetSSWins(int ssWins);
        int GetSSWins() const;
        virtual void Print() const override;
    private:
        int ssWins;
};

#endif
