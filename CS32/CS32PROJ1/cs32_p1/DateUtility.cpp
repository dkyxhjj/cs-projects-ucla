#include "DateUtility.h"

// Dummy implementation (students should replace)
bool DateUtility::isSixMonthsApart(const std::string& date1, const std::string& date2) {
    // parsing the data
    int month1 = std::stoi(date1.substr(0, 2));
    int day1 = std::stoi(date1.substr(3, 2));
    int year1 = std::stoi(date1.substr(6, 4));
    
    int month2 = std::stoi(date2.substr(0, 2));
    int day2 = std::stoi(date2.substr(3, 2));
    int year2 = std::stoi(date2.substr(6, 4));
    // input validation
    if (month1 < 1 || month1 > 12 || month2 < 1 || month2 > 12) {
        return false; // Invalid month
    }
    
    if (day1 < 1 || day1 > 31 || day2 < 1 || day2 > 31) {
        return false; // Invalid day
    }
    
    // Calculate total months difference
    int monthDiff = (year2 - year1) * 12 + (month2 - month1);
    
    // Handle negative differences 
    if (monthDiff < 0) {
        monthDiff = -monthDiff;
        // Swap days for comparison
        int tempDay = day1;
        day1 = day2;
        day2 = tempDay;
    }
    
    // More than 6 months apart
    if (monthDiff > 6) {
        return true;
    }
    
    // Less than 6 months apart
    if (monthDiff < 6) {
        return false;
    }
    
    // Exactly 6 months apart
    return day2 >= day1;
}

bool DateUtility::isSameDay(const std::string& d1, const std::string& d2) {
    return d1 == d2;
}
