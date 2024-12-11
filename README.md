# Food Expiration Checker

## Overview
A C++ application for managing food items and checking their expiration status. The program allows users to input detailed food information and verify whether a food item is still within its safe consumption period.

## Features
- Create and manage food items with comprehensive details
- Track production and expiration dates
- Validate food item's consumability
- Detailed input and output of food information

## Classes
### `date` Class
- Manages date-related operations
- Supports date validation
- Provides methods for setting and retrieving dates

### `Food` Class
- Stores comprehensive food item details
- Includes attributes:
  - Name
  - Price
  - Description
  - Ingredients
  - Cooking Methods
  - Production Date
  - Expiration Date

## Input Details
Users can input:
- Food name
- Description
- Ingredients
- Cooking methods
- Production date
- Expiration date

## Expiration Check Mechanism
- Compares production and expiration dates
- Provides a simple "safe/unsafe" recommendation

## Prerequisites
- C++ Compiler (supporting C++11 or later)
- Standard input/output libraries

## Compilation
```bash
g++ -std=c++11 food_expiration_checker.cpp -o food_expiration_checker
```

## Usage
1. Run the compiled executable
2. Enter food item details when prompted
3. Program displays food information
4. Receives a consumption recommendation

## Key Components
- Operator overloading for input/output
- Date validation
- Food item management
- Expiration status checking

## Potential Improvements
- Implement more robust date comparison
- Add more detailed expiration checks
- Create persistent storage mechanism
- Enhance input validation
- Support multiple food item management

## Limitations
- Basic date comparison logic
- Limited to console interface
- Simplified expiration checking

## License
Open-source MIT License

## Author
Salman Hashemi
