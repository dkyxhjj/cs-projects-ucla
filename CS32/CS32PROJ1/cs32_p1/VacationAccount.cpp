#include "VacationAccount.h"
#include "DateUtility.h"
#include <iostream>
#include <string> // for the helper function

VacationAccount::VacationAccount(int id) {
    if (id < 100000 || id > 999999) {
        mID = -1; // -1 if invalid
    } else {
        mID = id;
    }
    mBalance = 0.0;
    historySize = 0;
    donationHistory = nullptr;
}

VacationAccount::VacationAccount(const VacationAccount& other) {
    mID = other.mID;
    mBalance = other.mBalance;
    historySize = other.historySize;
    donationHistory = new BloodDonation*[historySize];
    for (int i = 0; i < historySize; ++i)
        donationHistory[i] = new BloodDonation(*other.donationHistory[i]);
}

VacationAccount::~VacationAccount() {
    for (int i = 0; i < historySize; ++i)
        delete donationHistory[i];
    delete[] donationHistory;
}

int VacationAccount::getID() const { return mID; }
double VacationAccount::getBalance() const { return mBalance; }

bool VacationAccount::addVacationToAccount(BloodDonation* donation) {
    if (!donation || donation->getID() != mID || donation->getID() == -1 ||
        donation->getAge() == -1 || donation->getWeight() == -1)
        return false;

    for (int i = 0; i < historySize; ++i) {
        if (DateUtility::isSameDay(donation->getDate(), donationHistory[i]->getDate()) ||
            !DateUtility::isSixMonthsApart(donation->getDate(), donationHistory[i]->getDate()))
            return false;
    }

    BloodDonation** newHistory = new BloodDonation*[historySize + 1];
    for (int i = 0; i < historySize; ++i)
        newHistory[i] = donationHistory[i];

    newHistory[historySize] = new BloodDonation(*donation);
    delete[] donationHistory;
    donationHistory = newHistory;
    historySize++;

    mBalance += 4.0;
    return true;
}

void VacationAccount::printDonationHistory() const {
    for (int i = 0; i < historySize; ++i)
        donationHistory[i]->print();
}

std::string VacationAccount::getDonationHistoryAsString() const {
    // start with an empty result
    std::string result = "";
    // loop from each donation in the array
    for (int i = 0; i < historySize; ++i) {
        result += "ID: " + std::to_string(donationHistory[i]->getID()) +
                 ", Age: " + std::to_string(donationHistory[i]->getAge()) +
                 ", Weight: " + std::to_string(donationHistory[i]->getWeight()) +
                 ", Date: " + donationHistory[i]->getDate();
        if (i < historySize - 1) {
            result += "\n";  // Add newline between entries
        }
    }
    return result;
}
