// Programmer: Marcos Gilbert | Course: CSC 155 | Lab 5 — Weather Analysis Station
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes -----------------------------------------------
double celsiusToFahrenheit(double c);
double fahrenheitToCelsius(double f);
double fahrenheitToKelvin(double k);
string classifyTemp(double celsius);
void   getMinMax(double a, double b, double& minVal, double& maxVal);
double computeHeatIndex(double tempC, double humidity);
void   printReading(int value);
void   printReading(double value);
bool   inputValidation(double& input);
bool   inputValidation(int& input);
//--------------------------------------------------------------------

int main() {
    int choice;         //variable for switch called choice
    cout << setprecision(2) << fixed;
    do {
        cout << "\n=== WEATHER ANALYSIS STATION ===\n"
        << "1. Convert Celsius to Fahrenheit\n"
        << "2. Convert Fahrenheit to Celsius\n"
        << "3. Convert Fahrenheit to Kelvin\n"
        << "4. Classify Temperature\n"
        << "5. Find min/max of two readings\n"
        << "6. Compute heat index\n"
        << "7. Print a reading (overload demo)\n"
        << "8. Quit\n";
        do {cout << "Choice: ";} while (!inputValidation(choice));              //ask for input for switch 
        switch (choice) {                     //* prompt, call celsiusToFahrenheit, display */ b
            case 1: {double c; do {cout << "Enter Celsius: ";} while (!inputValidation(c)); cout 
            << "Fahrenheit: " << celsiusToFahrenheit(c) << "°F" << '\n';} break;
            case 2: {double f; do {cout << "Enter Fahrenheit: ";} while (!inputValidation(f)); cout 
            << "Celsius: " << fahrenheitToCelsius(f) << "°C" << '\n';} break;
            case 3: {double k; do {cout << "Enter Fahrenheit: ";} while (!inputValidation(k)); cout     //creative feature
            << "Kelvin: " << fahrenheitToKelvin(k) << "K" << '\n';} break;
            case 4: {double t; do {cout << "Enter Celsius: ";} while (!inputValidation(t)); cout 
            << "Reading: " << classifyTemp(t) << '\n';} break;
            case 5: {double a, b, lo, hi; do {cout << "Enter Value 1: ";} while (!inputValidation(a)); 
            do {cout << "Enter Value 2: ";} while (!inputValidation(b)); getMinMax(a, b, lo, hi); 
            cout << "min=" << lo << ", max=" << hi << '\n';} break;
            case 6: {double tC; double hm; do {cout << "Enter temperature in Celsius: ";} while (!inputValidation(tC)); 
            do {cout << "Enter humidity: ";} while (!inputValidation(hm)); cout << "Heat Index: " 
            << computeHeatIndex(tC, hm) << "°C" << '\n';} break;
            case 7: {int s; double d; do {cout << "Input Reading 1 (int): ";} while (!inputValidation(s)); 
            do {cout << "Input Reading 2 (double): ";} while (!inputValidation(d)); printReading(s); printReading(d);} break;
            case 8: cout << "Goodbye\n";         break;
            default: cout << "Invalid choice\n"; break;
        }
    } while (choice != 8);                   //loops until choice is = 8
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
// Function : fahrenheitToCelsius
// Purpose  : Converts a temperature from Fahrenheit to Celsius
// Parameter: Equivalent temperature in Celsius
// Returns  : Equivalent in Celsius
// Test     : fahrenheitToCelsius(10)   -> -12.2222
//            fahrenheitToCelsius(15)   -> -9.4444
//            fahrenheitToCelsius(89)   -> 31.6667
// ─────────────────────────────────────────────────────────────
double fahrenheitToCelsius(double f) {
    return (f - 32) / 1.8;
}

// ─────────────────────────────────────────────────────────────
// Function : fahrenheitToKelvin
// Purpose  : Converts a temperature from Fahrenheit to Kelvin
// Parameter: Equivalent temperature in Kelvin
// Returns  : Equivalent in Kelvin
// Test     : fahrenheitToKelvin(89)   -> 304.82
//            fahrenheitToKelvin(100)  -> 310.928
//            fahrenheitToKelvin(70)   -> 294.261
// ─────────────────────────────────────────────────────────────
double fahrenheitToKelvin(double f) {
    return (f - 32) / 1.8 + 273.15;
}


// ─────────────────────────────────────────────────────────────
// Function : classifyTemp
// Purpose  : Classify the temperature based on the Celsius value
// Parameter: celsius — temperature in Celsius (passed by value)
// Returns  : A string indicating the temperature category
// Test     : classifyTemp(-5)  -> "Freezing"
//            classifyTemp(5)   -> "Cold"
//            classifyTemp(15)  -> "Mild"
//            classifyTemp(30)  -> "Hot"
//            classifyTemp(40)  -> "Extreme"
// ─────────────────────────────────────────────────────────────
string classifyTemp(double celsius) {
    if (celsius < 0) {
        return "Freezing";
    }
    else if (celsius >= 0 && celsius < 10) {            //changed to account for decimals
        return "Cold";
    }
    else if (celsius >= 10 && celsius < 25) {
        return "Mild";
    }
    else if (celsius >= 25 && celsius < 35) {
        return "Hot";
    }
    else {
        return "Extreme";
    }
}


// ─────────────────────────────────────────────────────────────
// Function : getMinMax
// Purpose  : Finds the minimum and maximum of two values
// Parameter: a, b — the two values to compare
// Returns  : The minimum value in minVal and the maximum value in maxVal (passed by reference)
// Test     : getMinMax(14.7, 22.3, lo, hi) -> lo=14.7, hi=22.3
//            getMinMax(22.3, 14.7, lo, hi) -> lo=14.7, hi=22.3
//            getMinMax(-5.0, 0.0, lo, hi)  -> lo=-5.0, hi=0.0
// ─────────────────────────────────────────────────────────────
void getMinMax(double a, double b, double& minVal, double& maxVal) {
    minVal = (a <= b) ? a : b;
    maxVal = (a >= b) ? a : b;
}
//  Calling it correctly:
//  double lo, hi;
//  getMinMax(14.7, 22.3, lo, hi);  // lo=14.7, hi=22.3 in the caller




// ─────────────────────────────────────────────────────────────
// Function : computeHeatIndex
// Purpose  : Return heat index
// Parameter: tempC — temperature in Celsius, humidity — relative humidity
// Returns  : Heat index
// Test     : computeHeatIndex(30.0, 70.0) -> 31.5
//            computeHeatIndex(25.0, 50.0) -> 24.5
//            computeHeatIndex(35.0, 80.0) -> 38.0
//          
// ─────────────────────────────────────────────────────────────
double computeHeatIndex(double tempC, double humidity) {
    return (tempC + (0.33 * humidity/100 * 6.105) - 4.0);
}



// ─────────────────────────────────────────────────────────────
// Function : printReading (overload 1)
// Purpose  : Prints an integer sensor reading with label and units
// Parameter: value — the integer reading to print
// Returns  : None
// Test     : printReading(72)   -> "Reading (int): 72 units"
//            printReading(0)    -> "Reading (int): 0 units"
//            printReading(-5)   -> "Reading (int): -5 units"
// ─────────────────────────────────────────────────────────────
void printReading(int value) {
    cout << setprecision(0) << "Reading (int): " << value << " units\n";
}
//prints an integer sensor reading with label and units.



// ─────────────────────────────────────────────────────────────
// Function : printReading (overload 2)
// Purpose  : Prints a double sensor reading with label and units
// Parameter: value — the double reading to print
// Returns  : None
// Test     : printReading(72.5)   -> "Reading (double): 72.5 units"
//            printReading(0.0)    -> "Reading (double): 0.0 units"
//            printReading(-5.5)   -> "Reading (double): -5.5 units"
// ─────────────────────────────────────────────────────────────
void printReading(double value) {
    cout << setprecision(1) << "Reading (double): " << value << " units\n";
}



// ─────────────────────────────────────────────────────────────
// Function : inputValidation
// Purpose  : Validates all the inputs before the functions so that program doesn't break
// Parameter: input — the value to validate
// Returns  : bool — true if valid, false otherwise
// Test     : inputValidation(5)   -> true
//            inputValidation(hi)  -> false
//            inputValidation(0)   -> true
// ─────────────────────────────────────────────────────────────
bool inputValidation(double& input) {

    if (cin >> input) {                    //check if input is valid and change input using &
        return true;
    }

    cout << "Invalid Input" << endl;      //else clean up cin and return false
    cin.clear();
    cin.ignore(1000, '\n');
    
    return false;
}
// ─────────────────────────────────────────────────────────────
// Function : inputValidation
// Purpose  : Validates all the inputs before the functions so that program doesn't break
// Parameter: input — the value to validate
// Returns  : bool — true if valid, false otherwise
// Test     : inputValidation(5)   -> true
//            inputValidation(hi)  -> false
//            inputValidation(0)   -> true
// ─────────────────────────────────────────────────────────────
bool   inputValidation(int& input) {

    if (cin >> input) {                    //check if input is valid and change input using &
        return true;
    }

    cout << "Invalid Input" << endl;      //else clean up cin and return false
    cin.clear();
    cin.ignore(1000, '\n');
    
    return false;
}





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

// POST labs excercises
// Excercise 2
// Gave me outputs of 0.00 for both instead of a na I thought they were going to give. Because the function isn't able to affect
// the originals it instead just affects copies. After affecting the copies the original values stay the same.
// When they get cout they show their original values. I thought I was going to get na because I got na previously
// when I tried this before on another lab.

// Excercise 3
// These are my outputs, it upgraded 72.0f to a double when I tried it, it still ran all three regardless.
// Choice: 6
// Reading (int): 72units
// Reading (double): 72.0units
// Reading (double): 72.4units

// Step 3 — Creative Feature Documentation

//     What function did you add? Write its complet e signature and describe what it does in one sentence.
//              double farheneittoKelvin(double f), it converts ferhenheit to kelvin using the formula (f - 32) / 1.8 + 273.15. And I added a way to do 
//          input validation much more efficently by using pass by reference.
//     Did you use pass-by-value or pass-by-reference in your new function, and why? What would go wrong if you had chosen the other approach?
//              I used both, I used pass-by-reference and pass-by-value. I used pass-by-reference for the validation
//              and then I used pass-by-value for the actual function doing the equation. I did this because the validation 
//              wouldn't be able to happen if it simply did cin because then the original variable wouldn't change, I also learned of
//              other ways of validating but this one seemed the most compressed. Otherwise I'd have to start doing if then statements.
//              If I used pass-by-reference for the actual function nothing would change because the        
//     Why did you choose this particular extension over other ideas you considered?
//              Because I wanted it to be optimized without having to do if statements all the time. I also wanted
//          it to relate to using functions like we learned in the labs. It was difficult to figure out how to 
//        use "!" in the same function notation as a function. I also learned that we could just use cin inside of a function
//          to change the original function which was very nice, I'm starting to realized that coding can be extremely intuitive
//          at times. I also wanted to convert farhenheit to kelvin as another way to measure temperature.
//     What would you add next to make this a more complete weather analysis tool — and what function design decisions would that require?
//              I would add a temperature predictor that takes the temperature x hours ago and compares it to the current temperature to 
//              show what the temperature could be in the desired hours with probability %