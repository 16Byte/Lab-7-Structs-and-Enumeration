/**
 * @file WeatherData.cpp
 * @brief Implementation of Weather Data functions with Enumerations
 * @author Lab 7 - Structs and Enumeration - Question 2
 */

#include "WeatherData.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Function implementations

string monthToString(Month month) {
    switch (month) {
        case JANUARY:   return "January";
        case FEBRUARY:  return "February";
        case MARCH:     return "March";
        case APRIL:     return "April";
        case MAY:       return "May";
        case JUNE:      return "June";
        case JULY:      return "July";
        case AUGUST:    return "August";
        case SEPTEMBER: return "September";
        case OCTOBER:   return "October";
        case NOVEMBER:  return "November";
        case DECEMBER:  return "December";
        default:        return "Unknown";
    }
}

bool isValidTemperature(double temperature) {
    return temperature >= MIN_TEMP && temperature <= MAX_TEMP;
}

double getValidTemperature(const string& prompt) {
    double temp;
    
    while (true) {
        cout << prompt;
        cin >> temp;
        
        // Check for input failure
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value.\n";
            continue;
        }
        
        // Validate temperature range
        if (!isValidTemperature(temp)) {
            cout << "Temperature must be between " << MIN_TEMP 
                 << " and " << MAX_TEMP << " degrees F.\n";
            continue;
        }
        
        // Echo the value back to show what was read
        cout << temp << endl;
        break;
    }
    
    return temp;
}

double getValidRainfall(const string& prompt) {
    double rainfall;
    
    while (true) {
        cout << prompt;
        cin >> rainfall;
        
        // Check for input failure
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value.\n";
            continue;
        }
        
        // Validate non-negative
        if (rainfall < 0) {
            cout << "Rainfall cannot be negative.\n";
            continue;
        }
        
        // Echo the value back to show what was read
        cout << rainfall << endl;
        break;
    }
    
    return rainfall;
}

void collectYearlyData(WeatherData yearData[]) {
    cout << "Please enter weather data for each month:\n\n";
    
    // Using enumerated type to iterate through months
    for (Month month = JANUARY; month < NUM_MONTHS; month = static_cast<Month>(month + 1)) {
        cout << "--- " << monthToString(month) << " ---\n";
        
        // Get rainfall
        yearData[month].totalRainfall = getValidRainfall("  Total rainfall (inches): ");
        
        // Get high temperature
        yearData[month].highTemperature = getValidTemperature("  High temperature (F): ");
        
        // Get low temperature
        yearData[month].lowTemperature = getValidTemperature("  Low temperature (F): ");
        
        // Calculate average temperature
        yearData[month].averageTemperature = 
            (yearData[month].highTemperature + yearData[month].lowTemperature) / 2.0;
        
        cout << "  Average temperature: " << fixed << setprecision(1) 
             << yearData[month].averageTemperature << " F\n\n";
    }
}

double calculateAverageRainfall(const WeatherData yearData[]) {
    return calculateTotalRainfall(yearData) / NUM_MONTHS;
}

double calculateTotalRainfall(const WeatherData yearData[]) {
    double total = 0.0;
    
    // Using enumerated type to iterate through months
    for (Month month = JANUARY; month < NUM_MONTHS; month = static_cast<Month>(month + 1)) {
        total += yearData[month].totalRainfall;
    }
    
    return total;
}

Month findHighestTempMonth(const WeatherData yearData[]) {
    Month maxMonth = JANUARY;
    
    // Using enumerated type to iterate through months
    for (Month month = FEBRUARY; month < NUM_MONTHS; month = static_cast<Month>(month + 1)) {
        if (yearData[month].highTemperature > yearData[maxMonth].highTemperature) {
            maxMonth = month;
        }
    }
    
    return maxMonth;
}

Month findLowestTempMonth(const WeatherData yearData[]) {
    Month minMonth = JANUARY;
    
    // Using enumerated type to iterate through months
    for (Month month = FEBRUARY; month < NUM_MONTHS; month = static_cast<Month>(month + 1)) {
        if (yearData[month].lowTemperature < yearData[minMonth].lowTemperature) {
            minMonth = month;
        }
    }
    
    return minMonth;
}

double calculateAverageOfAverages(const WeatherData yearData[]) {
    double sum = 0.0;
    
    // Using enumerated type to iterate through months
    for (Month month = JANUARY; month < NUM_MONTHS; month = static_cast<Month>(month + 1)) {
        sum += yearData[month].averageTemperature;
    }
    
    return sum / NUM_MONTHS;
}

void displayStatistics(const WeatherData yearData[]) {
    cout << "\n=================================================\n";
    cout << "              YEARLY WEATHER STATISTICS          \n";
    cout << "=================================================\n\n";
    
    // Average monthly rainfall
    cout << "Average monthly rainfall: " << fixed << setprecision(2)
         << calculateAverageRainfall(yearData) << " inches\n";
    
    // Total yearly rainfall
    cout << "Total yearly rainfall: " << fixed << setprecision(2)
         << calculateTotalRainfall(yearData) << " inches\n\n";
    
    // Highest temperature
    Month highestMonth = findHighestTempMonth(yearData);
    cout << "Highest temperature: " << fixed << setprecision(1)
         << yearData[highestMonth].highTemperature << " F in "
         << monthToString(highestMonth) << "\n";
    
    // Lowest temperature
    Month lowestMonth = findLowestTempMonth(yearData);
    cout << "Lowest temperature: " << fixed << setprecision(1)
         << yearData[lowestMonth].lowTemperature << " F in "
         << monthToString(lowestMonth) << "\n\n";
    
    // Average of monthly averages
    cout << "Average of all monthly average temperatures: " 
         << fixed << setprecision(1)
         << calculateAverageOfAverages(yearData) << " F\n";
    
    cout << "=================================================\n";
}
