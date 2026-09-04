// ============================================================
// Programmer  : Marcos Gilbert
// Course      : CSC 155 — C++ Computer Science I, Fall 2026
// Lab         : Lab 1 — Campus Energy Dashboard
// Date        : Aug 17
// Description : Reads campus energy data and produces a
//               formatted Energy Summary Report.
// ============================================================
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;
const int MAX_BUILDINGS = 10;
const double COST_PER_KWH = 0.1347;
const double CO2_PER_KWH = 0.386;


int main() {
int buildingCount;     // # of buildings
int maxBuildings = 5; // max buildings
string buildingName;   // name of building
double dailyKwh;       // kwh consumed today
double totalKwh;       // total across all buildings
double totalCost;      // electric cost in dollars
double totalCo2;       // total co2 emmissions
double avgKwh;         // avg consumption per building

cout << "\nHow many buildings are you reporting on? (1-" << maxBuildings << "):  ";
cin >> buildingCount;
cin.ignore(numeric_limits<streamsize>::max(), '\n');

for (int i = 1; i <= buildingCount; i++) {
    cout << "\nBuilding " << i << " Name: ";
    getline(cin, buildingName);

    cout << "Daily Kwh consumed: ";
    cin >> dailyKwh;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    totalKwh += dailyKwh;

    totalCost = totalKwh*COST_PER_KWH; // total electricity cost
    totalCo2 = totalKwh*CO2_PER_KWH;   // total carbon footprint in kg
    avgKwh = totalKwh/buildingCount;   // average consumption per building
}

cout << fixed << setprecision(2);      // set precision changes the decimal places in the report to 4
cout << '\n';
cout << "=========================================\n";
cout << "   OAKTON CAMPUS ENERGY SUMMARY REPORT\n";
cout << "=========================================\n";
cout << setw(28) << "Buildings reported:"; cout << setw(5) << buildingCount << '\n';
cout << setw(28) << "Total energy consumed: "; cout << setw(5) << totalKwh << " Kwh" << '\n';
cout << setw(28) << "Average energy consumption: "; cout << setw(5) << avgKwh << " Kwh" << '\n';
cout << setw(28) << "Total emissions: "; cout << setw(5) << totalCo2 << " Co2" << '\n';
cout << setw(28) << "Total cost: "; cout << "$ " << totalCost << '\n'; cout << '\n'; cout << '\n';


//prev days
    // | Day       | Energy usage |
    // | --------- | -----------: |
    // | Monday    |       5,389 kWh |
    // | Tuesday   |       6,901 kWh |
    // | Wednesday |       6,329 kWh |
    // | Thursday  |       6,923 kWh |
    // | Friday    |       5,403 kWh |
    // | Saturday  |       5,269 kWh |
const int Monday = 5389; const int Tuesday = 6901; const int Wednesday = 6329; 
const int Thursday = 6923; const int Friday = 5403; const int Saturday = 5269;
// plan: 1/n∑(xi - Mean)^2, = Variance
// we'll unsquare for standard deviation

int n = 7;
double Sum = Monday + Tuesday + Wednesday + Thursday + Friday + Saturday + totalKwh; 
double Mean = Sum / n;

double Variance = (pow(Monday - Mean, 2) + pow(Tuesday - Mean, 2) + pow(Wednesday - Mean, 2) + pow(Thursday - Mean, 2) + pow(Friday - Mean, 2) + pow(Saturday - Mean, 2) + pow(totalKwh - Mean, 2)) / n;
double standardDeviation = sqrt(Variance);
double zScore = (totalKwh - Mean) / Variance;
// sorry I would have made a real chart if I had a little more time to learn
cout << "=========================================\n";
cout << "      7 DAY ENERGY TREND REPORT\n";
cout << "=========================================\n";
cout << "|                                        " << '\n';
cout << "|                                        " << '\n';
cout << "|      ------      ------                " << '\n';
cout << "|     |      ------      |              _" << '\n';
cout << "|-----                    |            | " << '\n';
cout << "|                          ------------  " << '\n';
cout << "|                                        " << '\n';
cout << "|                                        " << '\n';
cout << "|.                                       " << '\n';
cout << " ----------------------------------------" << '\n';
cout << "Average consumption per day over 7 days: " << Mean << "Kwh" << '\n';
if (zScore > 1) {
    cout << "=High Usage";
}
else if (zScore < -1) {
    cout << "=Low Usage" << '\n';
}
else {
    cout << "=Normal Usage" << '\n';
}




int Overflow = 500000 * 8760;           //intentional overflow
long long noOverflow = 500000LL * 8760; //fixing overflow
cout << '\n' << "========================================" << '\n';
cout << setw(28) << "OVERFLOW EXAMPLE" << '\n';
cout << "========================================" << '\n';      // to make sure overflow doesn't happen we first make the variable long long
cout << setw(22) << "Overflow: "; cout << Overflow << '\n';      //then we make sure that atleast one integer has "LL"
cout << setw(22) << "No-Overflow: "; cout << noOverflow << '\n'; //we can't use int because C++ needs more space to store the number
cout << "\n ";                                                   //we need LL so C++ knows that the number multiplied is going to be big

int a = 5, b = 3;
cout << "5 / 3 (int): "   << a / b        << "\n";     // this calc produces the correct number because it has a ".0" after
cout << " 5.0 / 3 (double): " << 5.0 / b  << "\n";     // only when storing in a variable we use double
cout << " 10.0 / 4 (double too): " << 10.0/4 << "\n";

return 0;
}

    // What feature did you add? Describe it in 1–2 sentences.
    //      I added a way to see how high or low the usage was compared to the previous
    //      seven days using a z score.
    // What concept did you learn from the AI conversation that made this possible?
    //      I learned how to translate stats into coding which was completely new to me!
    // Why did you choose this particular feature over other ideas you considered?
    //      It was the first idea that came to mind, I learned about stats recently so I just wanted to use it :)
    // What would you add next if you had more time to extend this program?
    //      I would want to add a chart, a way to store previous days and future days. 