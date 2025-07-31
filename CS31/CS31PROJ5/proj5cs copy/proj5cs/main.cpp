#include <cassert>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

int main() {
    // Create an account
    FrequentFlyerAccount account("Richard");

    // Verify initial balance
    assert(account.getBalance() == 0);

    // Create valid flights
    PlaneFlight flight1("Richard", "New York", "Los Angeles", 250.50, 3000);
    PlaneFlight flight2("Richard", "Chicago", "Miami", 200, 1200);
    PlaneFlight flight3("Richard", "San Francisco", "Boston", 500, 3200);
    PlaneFlight flight4("Richard", "Dallas", "Seattle", 300, 1800);

    // Add flights to account
    assert(account.addFlightToAccount(flight1) == true);
    assert(account.addFlightToAccount(flight2) == true);
    assert(account.addFlightToAccount(flight3) == true);
    assert(account.getBalance() == 7400);

    // Edge Case: Adding a flight with different passenger name
    PlaneFlight flightWrongUser("Bob", "New York", "Los Angeles", 250.50, 3000);
    assert(account.addFlightToAccount(flightWrongUser) == false);
    assert(account.getBalance() == 7400); // Balance should remain unchanged

    // Edge Case 1
    PlaneFlight flightInvalidMileage("Richard", "Chicago", "Houston", 150, 0);
    assert(flightInvalidMileage.getMileage() == -1);
    assert(account.addFlightToAccount(flightInvalidMileage) == false);
    assert(account.getBalance() == 7400); // Mileage should not be added

    // Edge Case 2
    PlaneFlight flightInvalidCost("Richard", "Austin", "Denver", -100, 1500);
    assert(flightInvalidCost.getCost() == -1);
    assert(account.addFlightToAccount(flightInvalidCost) == true);
    assert(account.getBalance() == 8900);

    // Free flight eligibility
    assert(account.canEarnFreeFlight(5000) == true);
    assert(account.canEarnFreeFlight(10000) == false);

    // Redeem a free flight
    PlaneFlight freeFlight("", "", "", -1, -1);
    assert(account.freeFlight("Houston", "Orlando", 5000, freeFlight) == true);
    assert(freeFlight.getCost() == 0);
    assert(freeFlight.getMileage() == 5000);
    assert(freeFlight.getFromCity() == "Houston");
    assert(freeFlight.getToCity() == "Orlando");
    assert(account.getBalance() == 3900); 

    // Redeem an invalid freeflight
    assert(account.freeFlight("Las Vegas", "San Diego", 5000, freeFlight) == false);
    assert(account.getBalance() == 3900); // Mileage should remain unchanged

    return 0;
}
