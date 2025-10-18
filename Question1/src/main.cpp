/**
 * This program uses structures to store and analyze weather data for an entire year.
 * It collects monthly rainfall and temperature data, then calculates various statistics.
 */

#include "WeatherData.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

bool promptForTestInput() {
    string line;
    cout << "Would you like to use test input values? (Y/n): ";
    
    // Check if input has a value
    if (!getline(cin, line) || line.empty()) {
        // Default to 'Y' if user just presses enter
        return true;
    }
    
    // Check first character
    char response = line[0];
    return (response == 'Y' || response == 'y');
}

int main() {
    WeatherData yearData[NUM_MONTHS];
    
    cout << "=================================================\n";
    cout << "      Weather Statistics Program - Question 1    \n";
    cout << "=================================================\n\n";
    
    // Ask if user wants to use test input
    bool useTestInput = promptForTestInput();
    
    if (useTestInput) {
        // Redirect cin to read from test_input.txt
        ifstream testFile("test_input.txt");
        if (testFile.is_open()) {
            cout << "\n[Using test input from test_input.txt]\n\n";
            streambuf* cinbuf = cin.rdbuf();  // Save original cin buffer
            cin.rdbuf(testFile.rdbuf());      // Redirect cin to file
            
            // Collect data for all months
            collectYearlyData(yearData);
            
            cin.rdbuf(cinbuf);  // Restore original cin
            testFile.close();
        } else {
            cout << "\nWarning: test_input.txt not found. Using manual input instead.\n\n";
            collectYearlyData(yearData);
        }
    } else {
        // Collect data for all months
        collectYearlyData(yearData);
    }
    
    // Display statistics
    displayStatistics(yearData);
    
    return 0;
}
