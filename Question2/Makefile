# Makefile for Question 2 - Weather Statistics Program with Enumerations
# Lab 7 - Structs and Enumeration

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS =

# Directories
SRC_DIR = src
BUILD_DIR = build
INC_DIR = include

# Target executable
TARGET = $(BUILD_DIR)/weather_stats

# Source files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/WeatherData.cpp
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/WeatherData.o

# Default target - build and run
.PHONY: all
all: $(TARGET)
	@echo "==================================================="
	@echo "Running Weather Statistics Program (Question 2)"
	@echo "==================================================="
	@./$(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile main.cpp
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/WeatherData.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

# Compile WeatherData.cpp
$(BUILD_DIR)/WeatherData.o: $(SRC_DIR)/WeatherData.cpp $(INC_DIR)/WeatherData.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/WeatherData.cpp -o $(BUILD_DIR)/WeatherData.o

# Build only (no run)
.PHONY: build
build: $(TARGET)

# Run the program
.PHONY: run
run: $(TARGET)
	@./$(TARGET)

# Clean build artifacts
.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory"

# Rebuild from scratch
.PHONY: rebuild
rebuild: clean all

# Display help information
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make          - Build and run the program (default)"
	@echo "  make all      - Same as 'make'"
	@echo "  make build    - Build the program without running"
	@echo "  make run      - Run the program (builds if needed)"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make rebuild  - Clean and rebuild everything"
	@echo "  make help     - Show this help message"
