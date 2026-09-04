// Programmer  : Marcos Gilbert  |  Course: CSC 155  |  Lab 4 — Hospital Wait-Time Simulator
#include <string> 
#include <iostream>
#include <iomanip>
using namespace std;
const int TARGET_L1 = 0, TARGET_L2 = 15, TARGET_L3 = 30, TARGET_L4 = 60;
int triageLevel, waitMinutes;
int CountL1 = 0, CountL2 = 0, CountL3 = 0, CountL4 = 0;
int TotalL1 = 0, TotalL2 = 0, TotalL3 = 0, TotalL4 = 0;
int tCount = 0;
char continueSession;
int sessionChoice;


int main (){
// Requirements
//Use a do-while loop for the main session — keep processing patients until the user enters 0 to end the shift.
//Use a do-while loop for triage level input validation — keep prompting until the user enters 1–4.
//For each patient: record triage level (1–4) and actual wait time in minutes (must be ≥ 0). Accumulate total patients per level and total wait time per level.
//After the session ends, display a Shift Summary Report showing: patient count, average wait time, and whether the average wait met the target (comparison using if/else).
//Display overall totals: total patients seen, overall average wait time.
//Use a nested for loop to display a simple text-based wait-time bar chart (one * per 5 minutes of average wait) for each triage level.

do {
    cout << "\nSession choice (1 to add a patient, 0 to stop): ";
    cin >> sessionChoice;
    
    if (sessionChoice == 1) {
        do {
            cout << "Triage level (1=Immediate 2=Urgent 3=Less Urgent 4=Non-Urgent): ";
            cin.ignore();
            cin >> triageLevel;

            if (triageLevel < 1 || triageLevel > 4) {
                cout << "Invalid level. Enter 1-4.\n";
            }
        } while (triageLevel < 1 || triageLevel > 4);

    // makes sure that someone can't just input a negative number
    do {
    cout << "Actual wait time (minutes): ";
    cin >> waitMinutes;

    if (waitMinutes < 0) {
        cout << "Invalid Input, please try again.\n";
    }
    } while (waitMinutes < 0);

    if      (triageLevel == 1) {CountL1++; TotalL1 += waitMinutes; tCount++;}
    else if (triageLevel == 2) {CountL2++; TotalL2 += waitMinutes; tCount++;}
    else if (triageLevel == 3) {CountL3++; TotalL3 += waitMinutes; tCount++;}
    else                       {CountL4++; TotalL4 += waitMinutes; tCount++;}
    }
} while (sessionChoice != 0);

if (tCount == 0) {
    cout << "\nNo patients were processed during this session.\n";
    return 0;
}

// the averages
int avgL1 = 0, avgL2 = 0, avgL3 = 0, avgL4 = 0;

if (CountL1 > 0) {
    avgL1 = TotalL1 / CountL1;
}
if (CountL2 > 0) {
    avgL2 = TotalL2 / CountL2;
}
if (CountL3 > 0) {
    avgL3 = TotalL3 / CountL3;
}
if (CountL4 > 0) {
    avgL4 = TotalL4 / CountL4;
}

double oAvg = (TotalL1 + TotalL2 + TotalL3 + TotalL4) / tCount;

cout << "\n======================================\n";
cout << "   SHIFT SUMMARY — TRIAGE WAIT REPORT\n";
cout << "======================================\n";
cout << "Level 1 (Immediate):" << setw(5) << CountL1 << " patients   Avg: " << setw(3) << avgL1 << " min";
if (avgL1 <= TARGET_L1 && CountL1 > 0) {cout << " [TARGET MET]\n";} else if (avgL1 > TARGET_L1) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 2 (Urgent):" << setw(8) << CountL2 << " patients   Avg: " << setw(3) << avgL2 << " min";
if (avgL2 <= TARGET_L2 && CountL2 > 0) {cout << " [TARGET MET]\n";} else if (avgL2 > TARGET_L2) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 3 (Less Urgent):" << setw(3) << CountL3 << " patients   Avg: " << setw(3) << avgL3 << " min";
if (avgL3 <= TARGET_L3 && CountL3 > 0) {cout << " [TARGET MET]\n";} else if (avgL3 > TARGET_L3) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 4 (Non-Urgent):" << setw(4) << CountL4 << " patients   Avg: " << setw(3) << avgL4 << " min";
if (avgL4 <= TARGET_L4 && CountL4 > 0) {cout << " [TARGET MET]\n";} else if (avgL4 > TARGET_L4) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "--------------------------------------\n";
cout << "TOTAL: " << tCount 
<< " patients   Overall avg: " << setw(5) << oAvg << " min";

// print bar chart
for (int level = 1; level <= 4; level++) {
    int avgWait = 0;
    
    if (level == 1 ) {
        avgWait = avgL1;
    }
    else if (level == 2) {
        avgWait = avgL2;
    }
    else if (level == 3) {
        avgWait = avgL3;
    }
    else {
        avgWait = avgL4;
    }

    
    cout << "\nL: " << level << " ";
    for (int star = 0; star < avgWait / 5; star++ ) {
        cout << "*";
    }
    if (avgWait > 0) {
    cout << " (" << avgWait << " minutes)";
    }
}
    cout << "\n" << endl;
}


//Excercise 2
// Session choice (1 to add a patient, 0 to stop): 1
// Triage level (1=Immediate 2=Urgent 3=Less Urgent 4=Non-Urgent): 7
// Invalid level. Enter 1-4.
// Triage level (1=Immediate 2=Urgent 3=Less Urgent 4=Non-Urgent): 0
// Invalid level. Enter 1-4.
// Triage level (1=Immediate 2=Urgent 3=Less Urgent 4=Non-Urgent): -1
// Invalid level. Enter 1-4.
// Triage level (1=Immediate 2=Urgent 3=Less Urgent 4=Non-Urgent): 2
// Actual wait time (minutes): 



// //Excercise 3
//these were the outputs for only picking 0 for the program initially, I fixed it by putting a do while loop instead of the cout and cin by itself
//then I put a if statement to cout wether or not they put a valid input. Finally the while statement checks if they still input the incorrect thing.
// Session choice (1 to add a patient, 0 to stop): 0

// ======================================
//    SHIFT SUMMARY — TRIAGE WAIT REPORT
// ======================================
// Level 1 (Immediate):    0 patients   Avg:   0 min []
// Level 2 (Urgent):       0 patients   Avg:   0 min []
// Level 3 (Less Urgent):  0 patients   Avg:   0 min []
// Level 4 (Non-Urgent):   0 patients   Avg:   0 min []
// --------------------------------------
// TOTAL: 0 patients   Overall avg:     0 min
// L: 1
// L: 2
// L: 3
// L: 4