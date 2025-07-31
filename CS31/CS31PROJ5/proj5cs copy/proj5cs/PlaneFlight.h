#ifndef PLANEFLIGHT_H
#define PLANEFLIGHT_H

#include <string>

class PlaneFlight {
private:
    double mCost;
    std::string mFromCity;
    std::string mToCity;
    std::string mName;
    double mMileage;

public:
    // Constructor
    PlaneFlight(std::string passengerName, std::string fromCity, std::string toCity, double cost, double mileage);

    // Getter
    double getCost() const;
    double getMileage() const;
    std::string getName() const;
    std::string getFromCity() const;
    std::string getToCity() const;

    // Setter
    void setCost(double cost);
    void setMileage(double mileage);
    void setName(std::string name);
    void setFromCity(std::string from);
    void setToCity(std::string to);
};

#endif
