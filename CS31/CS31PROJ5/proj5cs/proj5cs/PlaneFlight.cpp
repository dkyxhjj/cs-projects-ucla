#include "PlaneFlight.h"

// Constructor
PlaneFlight::PlaneFlight(std::string passengerName, std::string fromCity, std::string toCity, double cost, double mileage) {
    setName(passengerName);
    setFromCity(fromCity);
    setToCity(toCity);
    setCost(cost);
    setMileage(mileage);
}

// Getters
double PlaneFlight::getCost() const {
    return mCost;
}

double PlaneFlight::getMileage() const {
    return mMileage;
}

std::string PlaneFlight::getName() const {
    return mName;
}

std::string PlaneFlight::getToCity() const{
    return mToCity;
}

std::string PlaneFlight::getFromCity() const{
    return mFromCity;
}


// Setters
void PlaneFlight::setCost(double cost){
    if (cost >= 0){
        mCost = cost;
    }
    else {
        mCost = -1;
    }
}

void PlaneFlight::setMileage(double mileage){
    if (mileage > 0){
        mMileage = mileage;
    }
    else {
        mMileage = -1;
    }
}

void PlaneFlight::setName(std::string name) {
    if (!name.empty()) {
        mName = name;
    }
}

void PlaneFlight::setFromCity(std::string from) {
    if (!from.empty() && from != mToCity) {
        mFromCity = from;
    }
}

void PlaneFlight::setToCity(std::string to) {
    if (!to.empty() && to != mFromCity) {
        mToCity = to;
    }
}

