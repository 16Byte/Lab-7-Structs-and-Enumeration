# Question 1 - Weather Statistics Program

## Overview
This program uses structures to store and analyze weather data for an entire year (12 months).

## Features
- Collects monthly rainfall and temperature data
- Validates temperature input (-100°F to 140°F)
- Automatically calculates average temperatures
- Displays comprehensive yearly statistics

## Project Structure
```
Question1/
├── Makefile              # Build automation
├── include/              # Header files
│   └── WeatherData.hpp   # Struct definitions and function prototypes
├── src/                  # Source files
│   ├── main.cpp         # Program entry point
│   └── WeatherData.cpp  # Function implementations
└── build/               # Compiled objects and executable (created by make)
```

## Building and Running

### Quick Start
```bash
make        # Build and run the program
```

When you run the program, you'll be prompted:
```
Would you like to use test input values? (Y/n):
```

- Type **Y** (or just press Enter) to automatically use the test data from `test_input.txt`
- Type **n** to enter weather data manually

### Available Commands
- `make` or `make all` - Build and run the program
- `make build` - Build the program without running
- `make run` - Run the program (builds if needed)
- `make clean` - Remove build artifacts
- `make rebuild` - Clean and rebuild from scratch
- `make help` - Show available commands

## Requirements Met
✅ Uses structures to organize weather data  
✅ Array of 12 structures for yearly data  
✅ Input validation for temperatures  
✅ Calculates all required statistics:
  - Average monthly rainfall
  - Total yearly rainfall  
  - Highest/lowest temperatures with months
  - Average of all monthly averages

## Documentation
All functions are documented using `///` summary style with:
- Function descriptions
- Parameter documentation (`<param>`)
- Return value documentation (`<returns>`)
