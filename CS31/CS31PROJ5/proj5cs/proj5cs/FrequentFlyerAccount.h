#ifndef FREQUENTFLYERACCOUNT_H
#define FREQUENTFLYERACCOUNT_H

#include <string>
#include "PlaneFlight.h"

class FrequentFlyerAccount{
private:
    std::string mName;
    double mBalance;
public:
    // Constructor
    FrequentFlyerAccount(std::string name);

    // Accessors
    double getBalance() const;
    std::string getName() const;

    // Methods
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage) const;
    bool freeFlight(std::string from, std::string to, double mileage, PlaneFlight &flight);
};


#endif
