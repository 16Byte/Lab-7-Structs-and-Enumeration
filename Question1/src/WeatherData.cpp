#include "WeatherData.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Month names array definition
const string MONTH_NAMES[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function implementations

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
        
        // Print the value back to show what was read
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
        
        // Print the value back to show what was read
        cout << rainfall << endl;
        break;
    }
    
    return rainfall;
}

void collectYearlyData(WeatherData yearData[]) {
    cout << "Please enter weather data for each month:\n\n";
    
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << "--- " << MONTH_NAMES[i] << " ---\n";
        
        // Get rainfall
        yearData[i].totalRainfall = getValidRainfall("  Total rainfall (inches): ");
        
        // Get high temperature
        yearData[i].highTemperature = getValidTemperature("  High temperature (F): ");
        
        // Get low temperature
        yearData[i].lowTemperature = getValidTemperature("  Low temperature (F): ");
        
        // Calculate average temperature
        yearData[i].averageTemperature = 
            (yearData[i].highTemperature + yearData[i].lowTemperature) / 2.0;
        
        cout << "  Average temperature: " << fixed << setprecision(1) 
             << yearData[i].averageTemperature << " F\n\n";
    }
}

double calculateAverageRainfall(const WeatherData yearData[]) {
    return calculateTotalRainfall(yearData) / NUM_MONTHS;
}

double calculateTotalRainfall(const WeatherData yearData[]) {
    double total = 0.0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        total += yearData[i].totalRainfall;
    }
    return total;
}

int findHighestTempMonth(const WeatherData yearData[]) {
    int maxIndex = 0;
    for (int i = 1; i < NUM_MONTHS; i++) {
        if (yearData[i].highTemperature > yearData[maxIndex].highTemperature) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findLowestTempMonth(const WeatherData yearData[]) {
    int minIndex = 0;
    for (int i = 1; i < NUM_MONTHS; i++) {
        if (yearData[i].lowTemperature < yearData[minIndex].lowTemperature) {
            minIndex = i;
        }
    }
    return minIndex;
}

double calculateAverageOfAverages(const WeatherData yearData[]) {
    double sum = 0.0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        sum += yearData[i].averageTemperature;
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
    int highestMonth = findHighestTempMonth(yearData);
    cout << "Highest temperature: " << fixed << setprecision(1)
         << yearData[highestMonth].highTemperature << " F in "
         << MONTH_NAMES[highestMonth] << "\n";
    
    // Lowest temperature
    int lowestMonth = findLowestTempMonth(yearData);
    cout << "Lowest temperature: " << fixed << setprecision(1)
         << yearData[lowestMonth].lowTemperature << " F in "
         << MONTH_NAMES[lowestMonth] << "\n\n";
    
    // Average of monthly averages
    cout << "Average of all monthly average temperatures: " 
         << fixed << setprecision(1)
         << calculateAverageOfAverages(yearData) << " F\n";
    
    cout << "=================================================\n";
}
