#ifndef WEATHERDATA_HPP
#define WEATHERDATA_HPP

#include <string>

// Structure to hold weather data for a single month
struct WeatherData {
    double totalRainfall;      // Total rainfall in inches
    double highTemperature;    // Highest temperature in Fahrenheit
    double lowTemperature;     // Lowest temperature in Fahrenheit
    double averageTemperature; // Average temperature (calculated)
};

// Constants
const int NUM_MONTHS = 12;
const double MIN_TEMP = -100.0;
const double MAX_TEMP = 140.0;
extern const std::string MONTH_NAMES[12];

// Function prototypes

// Purpose: Validates that a temperature is within the acceptable range
// Precondition: The temperature parameter is a valid double value
// Postcondition: Returns true if temperature is between -100 and 140 degrees F, false otherwise
// Returns: Boolean indicating if the temperature is valid
bool isValidTemperature(double temperature);

// Purpose: Gets a valid temperature input from the user with prompt
// Precondition: The prompt parameter contains a valid prompt string
// Postcondition: A valid temperature within the acceptable range is returned
// Returns: A valid temperature between -100 and 140 degrees F
double getValidTemperature(const std::string& prompt);

// Purpose: Gets a valid rainfall amount from the user
// Precondition: The prompt parameter contains a valid prompt string
// Postcondition: A non-negative rainfall amount is returned
// Returns: A non-negative rainfall value in inches
double getValidRainfall(const std::string& prompt);

// Purpose: Collects weather data for all 12 months from the user
// Precondition: yearData is an array of 12 WeatherData structures
// Postcondition: All 12 months of yearData are populated with user input, including calculated averages
void collectYearlyData(WeatherData yearData[]);

// Purpose: Calculates the average monthly rainfall across the year
// Precondition: yearData contains valid rainfall data for all 12 months
// Postcondition: The average monthly rainfall is calculated
// Returns: The average monthly rainfall in inches
double calculateAverageRainfall(const WeatherData yearData[]);

// Purpose: Calculates the total rainfall for the entire year
// Precondition: yearData contains valid rainfall data for all 12 months
// Postcondition: The total yearly rainfall is calculated
// Returns: The total yearly rainfall in inches
double calculateTotalRainfall(const WeatherData yearData[]);

// Purpose: Finds the month with the highest temperature
// Precondition: yearData contains valid temperature data for all 12 months
// Postcondition: The index of the month with the highest temperature is determined
// Returns: Index (0-11) of the month with the highest temperature
int findHighestTempMonth(const WeatherData yearData[]);

// Purpose: Finds the month with the lowest temperature
// Precondition: yearData contains valid temperature data for all 12 months
// Postcondition: The index of the month with the lowest temperature is determined
// Returns: Index (0-11) of the month with the lowest temperature
int findLowestTempMonth(const WeatherData yearData[]);

// Purpose: Calculates the average of all monthly average temperatures
// Precondition: yearData contains valid average temperatures for all 12 months
// Postcondition: The average of all monthly averages is calculated
// Returns: The average of all monthly average temperatures in degrees F
double calculateAverageOfAverages(const WeatherData yearData[]);

// Purpose: Displays all calculated statistics
// Precondition: yearData contains valid weather data for all 12 months
// Postcondition: All yearly statistics are displayed to the console
void displayStatistics(const WeatherData yearData[]);

#endif // WEATHERDATA_HPP
