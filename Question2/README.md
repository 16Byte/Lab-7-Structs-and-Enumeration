# Question 2 - Weather Statistics Program with Enumerations

## Overview
This program extends Question 1 by using enumerated types for months. It demonstrates the use of enums to step through array elements while maintaining all the weather statistics functionality.

## Features
- Uses `enum Month` (JANUARY, FEBRUARY, etc.)
- Enums used to iterate through array elements
- All statistics features from Question 1
- Type-safe month handling

## Project Structure
```
Question2/
├── Makefile              # Build automation
├── include/              # Header files
│   └── WeatherData.hpp   # Enum definitions, struct, and function prototypes
├── src/                  # Source files
│   ├── main.cpp         # Program entry point
│   └── WeatherData.cpp  # Function implementations with enum usage
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

## Key Differences from Question 1
- **Enumerated Month Type**: Uses `enum Month` instead of integer indices
- **Type Safety**: Month values are type-checked at compile time
- **Iterator Pattern**: Demonstrates proper enum iteration in loops
- **Helper Function**: `monthToString()` converts enum to readable names

## Requirements Met
✅ Defines enumerated data type for months  
✅ Uses enumerators (JANUARY, FEBRUARY, etc.)  
✅ Uses enumerated type to step through array elements  
✅ All Question 1 features maintained  
✅ Comprehensive documentation with `///` style

## Code Example
```cpp
// Using enum to iterate through months
for (Month month = JANUARY; month < NUM_MONTHS; 
     month = static_cast<Month>(month + 1)) {
    // Process each month
}
```

## Documentation
All functions are documented using `///` summary style with:
- Function descriptions
- Parameter documentation (`<param>`)
- Return value documentation (`<returns>`)
