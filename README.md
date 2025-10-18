# Lab 7 - Structs and Enumeration

## Project Overview
This lab demonstrates the use of structures (structs) and enumerations (enums) in C++ through a weather statistics program.

## Directory Structure
```
Lab-7-Structs-and-Enumeration/
├── Question1/              # Weather statistics using structs
│   ├── include/           # Header files
│   │   └── WeatherData.hpp
│   ├── src/              # Source files
│   │   ├── main.cpp
│   │   └── WeatherData.cpp
│   ├── Makefile          # Build automation
│   └── README.md         # Question 1 documentation
│
├── Question2/              # Weather statistics with enums
│   ├── include/           # Header files
│   │   └── WeatherData.hpp
│   ├── src/              # Source files
│   │   ├── main.cpp
│   │   └── WeatherData.cpp
│   ├── Makefile          # Build automation
│   └── README.md         # Question 2 documentation
│
└── README.md              # This file
```

## Questions Solved

### Question 1 (50 points)
A program that uses structures to store weather data for an entire year:
- Monthly rainfall, high/low temperatures
- Temperature validation (-100°F to 140°F)
- Calculates yearly statistics

**Location:** `Question1/`

### Question 2 (50 points)
Extends Question 1 by adding enumerated types for months:
- Enum Month (JANUARY, FEBRUARY, etc.)
- Uses enums to iterate through array elements
- Demonstrates type-safe month handling

**Location:** `Question2/`

## Building and Running

### Question 1
```bash
cd Question1
make        # Build and run
make help   # See all available commands
```

### Question 2
```bash
cd Question2
make        # Build and run
make help   # See all available commands
```

## Features

### Both Programs Include:
✅ **Proper code organization** - Separated headers and implementation  
✅ **Comprehensive documentation** - Using `///` summary style with `<param>` and `<returns>` tags  
✅ **Input validation** - Temperatures must be between -100°F and 140°F  
✅ **Automatic calculations** - Average temperatures computed  
✅ **Detailed statistics** - All required yearly metrics  
✅ **Build automation** - Makefiles with multiple targets  
✅ **Clean structure** - Modular, maintainable code  

### Statistics Calculated:
- Average monthly rainfall
- Total yearly rainfall
- Highest temperature (with month)
- Lowest temperature (with month)
- Average of all monthly average temperatures

## Documentation Style
All functions use the `///` documentation format:
```cpp
/// <summary>
/// Brief description of what the function does
/// </summary>
/// <param name="paramName">Description of parameter</param>
/// <returns>Description of return value</returns>
```

## Compilation
- Compiler: g++
- Standard: C++11
- Flags: -Wall -Wextra (strict warnings enabled)
- Zero warnings on compilation ✨

## Testing
Both programs have been tested and verified to:
- Compile cleanly without warnings
- Validate input correctly
- Calculate statistics accurately
- Handle edge cases properly

## Submission
Each question is in its own folder with:
- Modular C++ source files (.cpp)
- Header files (.hpp)
- Makefile for easy compilation
- README with documentation
- Full comments and specifications (15 points requirement met!)

---

**Author:** Lab 7 Assignment  
**Course:** OOP Class  
**Date:** October 2025
