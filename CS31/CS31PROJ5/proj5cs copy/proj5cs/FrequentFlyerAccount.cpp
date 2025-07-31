#include "FrequentFlyerAccount.h"

// Constructor
FrequentFlyerAccount::FrequentFlyerAccount(std::string name) {
    mName = name;
    mBalance = 0; // Initial mileage balance
}

// Getters
double FrequentFlyerAccount::getBalance() const {
    return mBalance;
}

// Get the account holder's name
std::string FrequentFlyerAccount::getName() const {
    return mName;
}

// Add flight function
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if (flight.getName() == mName && flight.getMileage() > 0) { 
        mBalance += flight.getMileage();
        return true;
    }
    return false;
}


// Free flight checker function
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) const {
    if (mBalance >= mileage){
        return true;
    }
    return false;
}

// Free flight function
bool FrequentFlyerAccount::freeFlight(std::string from, std::string to, double mileage, PlaneFlight &flight){
    if (canEarnFreeFlight(mileage)){
        mBalance -= mileage;
        flight = PlaneFlight(mName, from, to, 0, mileage);
        return true;
    }
    return false;
}
