//
//  main.cpp
//  cs32_p1
//
//  Created by Richard Li on 2025-06-28.
//
#include "BloodDonation.h"
#include "DateUtility.h"
#include "VacationAccount.h"
#include <iostream>
#include <cassert>

int main(int argc, const char * argv[]) {
    // Case 1, proper constructor
    BloodDonation donation1(123456, 34, 150.5, "01/15/2024");
    assert(donation1.getID() == 123456);
    assert(donation1.getAge() == 34);
    assert(donation1.getWeight() == 150.5);
    assert(donation1.getDate() == "01/15/2024");
    
    // Case 2, partial constructor
    BloodDonation donation2(123482);
    assert(donation2.getID() == 123482);
    assert(donation2.getAge() == -1);
    assert(donation2.getWeight() == -1);
    assert(donation2.getDate() == "");
    
    // Case 3, Valid and invalid ID Setting
    BloodDonation donation3(100000);
    donation3.setID(234567);
    assert(donation3.getID() == 234567);
    donation3.setID(11111);
    assert(donation3.getID() == - 1);
    
    // Case 4, Valid and invalid age setting
    donation3.setAge(30);
    assert(donation3.getAge() == 30);
    donation3.setAge(19);
    assert(donation3.getAge() == -1);
    donation3.setAge(99);
    assert(donation3.getAge() == -1);
    
    // Case 5, Valid and invalid weight setting
    donation3.setWeight(120.5);
    assert(donation3.getWeight() == 120.5);
    donation3.setWeight(100.0);
    assert(donation3.getWeight() == -1);
    donation3.setWeight(355.0);
    assert(donation3.getWeight() == -1);
    
    // Case 6, test vacation account setup
    VacationAccount account(111111);
    assert(account.getID() == 111111);
    
    // Case 7, testing adding donation
    BloodDonation* donation4 = new BloodDonation(111111, 25, 150.0, "01/15/2024");
    bool added = account.addVacationToAccount(donation4);
    assert(added == true);
    
    // Case 8, testing duplicated donation on same day
    VacationAccount account1(222222);
    BloodDonation* donation5 = new BloodDonation(222222, 30, 160.0, "02/01/2024");
    BloodDonation* donation6 = new BloodDonation(222222, 35, 170.0, "02/01/2024");
    bool added1 = account1.addVacationToAccount(donation5);
    bool added2 = account1.addVacationToAccount(donation6);
    assert(added1 == true);
    assert(added2 == false); // rejected because it's on the same day
    assert(account1.getBalance() == 4); // Only first donation should count
    
    delete donation6; //donation 6 is no use anymore
    
    // Case 9, testing the 6 month rule
    VacationAccount account2(444444);
    BloodDonation* donation7 = new BloodDonation(444444, 28, 155.0, "01/01/2024");
    BloodDonation* donation8 = new BloodDonation(444444, 29, 165.0, "03/01/2024"); //within 2 months
    bool added3 = account2.addVacationToAccount(donation7);
    bool added4 = account2.addVacationToAccount(donation8);
    assert(added3 == true);
    assert(added4 == false);
    assert(account2.getBalance() == 4); // Only first donation should count
    
    // Case 9, testing multiple valid acceptances
    VacationAccount account3(666666);
    BloodDonation* donation9 = new BloodDonation(666666, 32, 145.0, "01/01/2023");
    BloodDonation* donation10 = new BloodDonation(666666, 33, 148.0, "08/01/2023"); // 7 months later
    BloodDonation* donation11 = new BloodDonation(666666, 34, 150.0, "03/01/2024"); // 7 months after that
    bool added5 = account3.addVacationToAccount(donation9);
    bool added6 = account3.addVacationToAccount(donation10);
    bool added7 = account3.addVacationToAccount(donation11);
    assert(added5 == true);
    assert(added6 == true);
    assert(added7 == true);
    assert(account3.getBalance() == 12);
    
    // Case 10, testing history output
    std::string expected = "ID: 666666, Age: 32, Weight: 145.000000, Date: 01/01/2023\nID: 666666, Age: 33, Weight: 148.000000, Date: 08/01/2023\nID: 666666, Age: 34, Weight: 150.000000, Date: 03/01/2024";
    std::string actual = account3.getDonationHistoryAsString();
    assert(expected==actual);
    
    // Case 11, testing another history output
    std::string expected1 = "ID: 444444, Age: 28, Weight: 155.000000, Date: 01/01/2024";
    std::string actual1 = account2.getDonationHistoryAsString();
    assert(expected==actual);

    // Case 12, testing invalid date
    VacationAccount account4(123457);
    BloodDonation* donation12 = new BloodDonation(666666, 32, 145.0, "34/01/2023");
    bool added8 = account4.addVacationToAccount(donation12); // should be false because invalid date
    assert(added8 == false);
    
    
    
    
    
    
}
