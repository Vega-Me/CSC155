// ============================================================
// Programmer : Marcos Gilbert
// Course     : CSC 155 — Computer Science I
// Lab        : Lab 2 — Flight Risk Screener
// Description: Screens passengers against boarding criteria and
//              generates a flight boarding summary report.
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX_PASSENGERS = 20;

int     passengerCount;            //total passengers to screen
int     clearedCount  = 0;         //passengers who cleared screening
int     deniedCount   = 0;         //passengers denied boarding
int     firstClass    = 0;         //count of first-class selections
int     businessClass = 0;         //count of business selections
int     economyClass  = 0;         //count of economy selections
string passengerName;              //name of current passenger
int age;                           //passenger age
char noFlyResponse;                //y/n - is passenger on the no fly list?
char idResponse;                   //y/n - does passenger have valid ID?
bool onNoFlyList;                  //true if on no-fly registry
bool hasValidId;                   //true if valid ID presented
int seatChoice;                    //1=economy, 2=business, 3=first               

//added these for creative portion
const int fclassCost = 1200;
const int bclassCost = 700;
const int eclassCost = 500;

int steakCount = 0;
int salmonCount = 0;
int turkeyCount = 0;
const int steakMeal = 15;
const int salmonMeal = 22;
const int turkeyMeal = 16;


int main(){
    cout << "\n";
    cout << "Passenger Count: ";
    cin >> passengerCount;
    cin.ignore(1000, '\n');

    for (int i = 1; i <= passengerCount; i++) {
        cout << "\n--- Passenger " << i << " of " << passengerCount << " ---\n";
        cout << "Passenger name: ";
        getline(cin, passengerName);

        cout << "Age: ";
        cin >> age;

        cout << "On no-fly list? (Y/N): ";
        cin >> noFlyResponse;
        onNoFlyList = (noFlyResponse == 'y' || noFlyResponse == 'Y');
        
        cout << "Valid government ID? (Y/N): ";
        cin >> idResponse;
        hasValidId = (idResponse == 'y' || idResponse == 'Y');
        cin.ignore();

        //elgibility screening logic
        if (age < 12) {
            cout << "DENIED: " << passengerName << " - minimum age not met.\n";
            deniedCount++;
        } 
        else if (onNoFlyList || !hasValidId) {        //design requirement for step 4?
            cout << "DENIED: " << passengerName << " - passenger on no-fly list and no valid Id.\n";
            deniedCount++;
        } 
        else {
            cout << "CLEARED: " << passengerName << "\n";
            clearedCount++;

             cout << "Select seat class:\n"
        << " 1 - Economy\n"
        << " 2 - Business\n"
        << " 3 - First Class\n"
        << "Choice: ";
        cin >> seatChoice;
        cin.ignore();

        switch (seatChoice) {
            case 1: economyClass++; cout << "Economy Confirmed.\n";       break; // breaking makes it default to economy
            case 2: businessClass++;cout << "Business Confirmed.\n";      break;
            case 3: firstClass++;   cout << "First Class Confirmed.\n";   break;
            default: cout << "Invalid Choice - defaulting to economy.\n";
            economyClass++; break;}



            //foods
            cout << '\n' << "On flight amenities?:\n"
        << " 1 - Turkey Dinner\n"
        << " 2 - Smoked Salmon\n"
        << " 3 - Sliced Prime Rib\n"
        << "Choice: ";
        cin >> seatChoice;
        cin.ignore();

        switch (seatChoice) {
            case 1: turkeyCount++; cout << "Turkey Dinner Ordered.\n";       break; // breaking makes it default to economy
            case 2: salmonCount++; cout << "Smoked Salmon Ordered.\n";      break;
            case 3: steakCount++;  cout << "Sliced Prime Rib Ordered.\n";   break;
            default: cout << "Invalid Choice - no dinner ordered.\n"; break;}

        }
    }
    int foodRevenue = ((steakMeal * steakCount) + (salmonMeal * salmonCount) + (turkeyCount * turkeyMeal));
    int seatRevenue = (fclassCost * firstClass) + (bclassCost * businessClass) + (eclassCost * economyClass);
        //report: total passengers, cleared count, denied count, seat class percentages
        //set w for alignment         fixed + setprecision(1) for percent
    cout << fixed << setprecision(1);
    cout << "\n============================================\n";
    cout << "      REGIONAL AIR -- BOARDING SUMMARY" << '\n';
    cout << "============================================\n";
    cout << "     Passengers screened:  " << setw(5) << passengerCount << '\n';
    cout << "     Cleared for boarding: " << setw(5) << clearedCount << setprecision(1) << " ( " << (static_cast<double>(clearedCount)/passengerCount) * 100 << "% ) " <<  '\n';
    cout << "     Denied boarding:      " << setw(5) << deniedCount << " ( " << (static_cast<double>(deniedCount)/passengerCount) * 100 << "% ) " << '\n';
    cout << "--------------------------------------------\n";
    cout << "     Economy seats:        " << setw(5) << economyClass << '\n';
    cout << "     Business seats:       " << setw(5) << businessClass << '\n';
    cout << "     First Class seats:    " << setw(5) << firstClass << '\n';
    cout << "============================================\n";
    cout << "     Steak meals:        " << setw(5) << steakCount << '\n';
    cout << "     Salmon meals:       " << setw(5) << salmonCount << '\n';
    cout << "     Turkey meals:       " << setw(5) << turkeyCount << '\n';
    cout << "============================================\n";
    cout << "     Food revenue:       " << setw(5) << "$ " << foodRevenue << "\n";     
    cout << "     Seat revenue:       " << setw(5) << "$ " << seatRevenue << "\n";
    cout << "     Total revenue:      " << setw(5) << "$ " << seatRevenue + foodRevenue << "\n";
    cout << "============================================\n";


        //reference
        // ============================================
        //         REGIONAL AIR — BOARDING SUMMARY
        // ============================================
        //        Passengers screened:           5
        //        Cleared for boarding:          2  ( 40.0%)
        //        Denied boarding:               3  ( 60.0%)
        // --------------------------------------------
        //        Economy seats:                 0
        //        Business seats:                1
        //        First Class seats:             1
        // ============================================
}



//excercise 3
//With the current code the denial message that appears is the minimum age not met.
//Instead the denial message is that the person is on the no fly list when we swap the two. 
//What this tells me is that order matters in our design choice, but it also shows the different
//ways that we can change the code to get a result for either or instead of just one.

//creative feature
// What feature did you add? Describe it in 1–2 sentences.
//  -added a revenue summary for the screener to show how much was made off the tickets and and seat choices.
// What principle about decision logic design did you learn from the AI conversation that shaped your implementation?
//  -how a customer choosing a item can affect later decisions, how it can also change the order in which calculations are done.
// Why did you choose this feature over other ideas you considered during the conversation?
//  -because if the airline doesn't keep track of the revenue then it goes out of business.
// What would you add next if you had more time — and how would the concept you learned apply to that extension?
//  -I would want to add discounts based on military/disabled. I would also want to have choices for luggage quantity or pets.

//notes:
//added seat revenue count 
//added food count
//added food revenue
