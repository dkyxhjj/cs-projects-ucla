#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    // Declaration of all of the variables
    string customer, typeOfCoffee, dayOfWeek, extraItems;
    int cups;
    double total;
    
    // Initilizing variables by taking in inputs
    cout << "Customer's first name: " ;
    getline(cin, customer);

    cout << "Number of cups: ";
    cin >> cups;
    
    cout << "Types of coffee (r=regular, d=decaf): ";
    cin >> typeOfCoffee;

    cout << "Any extra items? (y/n): ";
    cin >> extraItems;

    cout << "Day of the week: ";
    cin >> dayOfWeek;
    
    // First input validation, we check if the name is empty, or the first letter isn't capitalized
    // We return the error message and terminate the program if this don't validate
    if (customer.empty() || !isupper(customer[0])){
        cout << "---\n";
        cout << "The first name must start with an uppercase letter." << endl;
        return 1;
    }
    
    // Second input validation to check if cups is assigned a negative number
    // Terminate the program and error message if this don't validate
    if (cups < 0){
        cout << "---\n";
        cout << "The number of cups must be positive." << endl;
        return 2;
    }
    
    // Third input validation to check if anything other than "r" or "d" is assigned
    if (typeOfCoffee != "r" && typeOfCoffee != "d"){
        cout << "---\n";
        cout << "You must enter r or d. " << endl;
        return 3;
    }
    
    // Fourth input validation to check if anything other than "y" or "n" is assigned
    if (extraItems != "y" && extraItems != "n"){
        cout << "---\n";
        cout << "You must enter y or n. " << endl;
        return 4;
    }
    
    // Last input validation to check if the days entered is valid
    if (dayOfWeek != "Monday" && dayOfWeek != "Tuesday" && dayOfWeek != "Wednesday" && dayOfWeek != "Thursday" && dayOfWeek != "Friday" && dayOfWeek != "Saturday" && dayOfWeek != "Sunday" ){
        cout << "---\n";
        cout << "You must enter a valid day of the week. " << endl;
        return 5;
    }
    
    // Display in fixed-point notation, set the precision to 2 decimal places, and always show decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Calculation on the final output after input validation
    if (typeOfCoffee == "r"){
        total = cups * 4.00;
    }
    else {
        total = cups * 4.50;
    }
    
    if (extraItems == "y"){
        total += 1.95;
    }
    
    if (dayOfWeek == "Wednesday") {
        total *= 0.85;
    }
    
    // Final output
    cout << "---\n";
    cout << "The total charge for " << customer << " is $" << total << endl;
    return 0;
}
