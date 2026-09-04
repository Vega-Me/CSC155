// Programmer: Marcos Gilbert | Course: CSC 155 | Lab 5 — Weather Analysis Station
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes -----------------------------------------------
double celsiusToFahrenheit(double c);
double fahrenheitToCelsius(double f);
string classifyTemp(double celsius);
void   getMinMax(double a, double b, double& minVal, double& maxVal);
double computeHeatIndex(double tempC, double humidity);
void   printReading(int value);
void   printReading(double value);
//--------------------------------------------------------------------

int main() {


}


// ─────────────────────────────────────────────────────────────
// Function : celsiusToFahrenheit
// Purpose  : Converts a temperature from Celsius to Fahrenheit
// Parameter: c — temperature in Celsius (passed by value)
// Returns  : Equivalent temperature in Fahrenheit
// Test     : celsiusToFahrenheit(0.0)   → 32.0
//            celsiusToFahrenheit(100.0) → 212.0
//            celsiusToFahrenheit(-40.0) → -40.0
// ─────────────────────────────────────────────────────────────
double celsiusToFahrenheit(double c) {
    return c * 1.8 + 32;
}


// ─────────────────────────────────────────────────────────────
// Function : 
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
double fahrenheitToCelsius(double f);


// ─────────────────────────────────────────────────────────────
// Function : 
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
string classifyTemp(double celsius);


// ─────────────────────────────────────────────────────────────
// Function : getMinMax
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
void getMinMax(double a, double b, double& minVal, double& maxVal) {
    minVal = (a <= b) ? a : b;  // stores result directly in caller's variable
    maxVal = (a >= b) ? a : b;
}

// Calling it correctly:
double lo, hi;
getMinMax(14.7, 22.3, lo, hi);  // lo=14.7, hi=22.3 in the caller



// ─────────────────────────────────────────────────────────────
// Function : 
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
double computeHeatIndex(double tempC, double humidity);



// ─────────────────────────────────────────────────────────────
// Function : 
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
void   printReading(int value);



// ─────────────────────────────────────────────────────────────
// Function : 
// Purpose  : 
// Parameter: 
// Returns  : 
// Test     : 1
//            2
//            3
// ─────────────────────────────────────────────────────────────
void   printReading(double value);







//========================================================================================

// Required Function Signatures

// 1. double celsiusToFahrenheit(double c)
//    - Returns: double
//    - Description: Converts Celsius to Fahrenheit using the standard formula.
//    - Pass type: By value

// 2. double fahrenheitToCelsius(double f)
//    - Returns: double
//    - Description: Converts Fahrenheit to Celsius.
//    - Pass type: By value

// 3. string classifyTemp(double celsius)
//    - Returns: string
//    - Description:
//      - "Freezing" if celsius < 0
//      - "Cold" if celsius is 0–9
//      - "Mild" if celsius is 10–24
//      - "Hot" if celsius is 25–34
//      - "Extreme" if celsius >= 35
//    - Pass type: By value

// 4. void getMinMax(double a, double b, double& minVal, double& maxVal)
//    - Returns: void
//    - Description: Finds the minimum and maximum of two values.
//    - Stores the minimum in minVal and maximum in maxVal.
//    - a and b are passed by value.
//    - minVal and maxVal are passed by reference.

// 5. double computeHeatIndex(double tempC, double humidity)
//    - Returns: double
//    - Description: Returns a simplified heat index in Celsius.
//    - Formula:
//      HI = tempC + (0.33 * humidity / 100 * 6.105) - 4.0
//    - Pass type: By value

// 6. void printReading(int value)
//    - Overload 1
//    - Returns: void
//    - Description: Prints an integer sensor reading with a label and units.
//    - Pass type: By value

// 7. void printReading(double value)
//    - Overload 2
//    - Returns: void
//    - Description: Prints a double sensor reading formatted to 2 decimal places with a label and units.
//    - Pass type: By value


//========================================================================================
//PRELAB excercise
// & means give orignal
// nothing = give copy

//int double string | compiler picks right one when multiple functions have the same name
//void printReading(int value) || void printReading(double value)

// double temp;
// double convertTemp(double fahrenheit) {
//     double celsius = (fahrenheit - 32.0);
//     return celsius;
// }

// int main () {
// cout << "Pick a temp: ";
// cin >> temp;
// cout << convertTemp(temp);

// }



// string text;

// void stormwarning(string, int) {
//     cout << "first one worked";
// }
// void stormwarning(string) {
//     cout << "second one worked";
// }
//========================================================================================