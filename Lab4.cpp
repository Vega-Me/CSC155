// Programmer  : Marcos Gilbert  |  Course: CSC 155  |  Lab 4 — Hospital Wait-Time Simulator
#include <string> 
#include <iostream>
#include <iomanip>
using namespace std;
const int TARGET_L1 = 0, TARGET_L2 = 15, TARGET_L3 = 30, TARGET_L4 = 60;
int triageLevel, waitMinutes;
int CountL1 = 0, CountL2 = 0, CountL3 = 0, CountL4 = 0;
int TotalL1 = 0, TotalL2 = 0, TotalL3 = 0, TotalL4 = 0;
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

    cout << "Actual wait time (minutes): ";
    cin >> waitMinutes;

    if      (triageLevel == 1) {CountL1++; TotalL1 += waitMinutes;}
    else if (triageLevel == 2) {CountL2++; TotalL2 += waitMinutes;}
    else if (triageLevel == 3) {CountL3++; TotalL3 += waitMinutes;}
    else                       {CountL4++; TotalL4 += waitMinutes;}
    }
} while (sessionChoice != 0);


// the averages
double avgL1 = 0, avgL2 = 0, avgL3 = 0, avgL4 = 0;
if (CountL1 > 0) {
    avgL1 = static_cast<double>(TotalL1) / CountL1;
}
if (CountL2 > 0) {
    avgL2 = static_cast<double>(TotalL2) / CountL2;
}
if (CountL3 > 0) {
    avgL3 = static_cast<double>(TotalL3) / CountL3;
}
if (CountL4 > 0) {
    avgL4 = static_cast<double>(TotalL4) / CountL4;
}


cout << "\n======================================\n";
cout << "   SHIFT SUMMARY — TRIAGE WAIT REPORT\n";
cout << "======================================\n";
cout << "Level 1 (Immediate):" << setw(5) << CountL1 << " patients   Avg: " << setw(3) << avgL1 << " min";
if (avgL1 <= TARGET_L1 && CountL1 > 0) {cout << " [TARGET MET]\n";} else if (avgL1 > TARGET_L1) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 2 (Urgent):" << setw(8) << CountL2 << " patients   Avg: " << setw(3) << avgL2 << " min";
if (avgL2 <= TARGET_L1 && CountL2 > 0) {cout << " [TARGET MET]\n";} else if (avgL2 > TARGET_L1) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 3 (Less Urgent):" << setw(3) << CountL3 << " patients   Avg: " << setw(3) << avgL3 << " min";
if (avgL3 <= TARGET_L1 && CountL3 > 0) {cout << " [TARGET MET]\n";} else if (avgL3 > TARGET_L1) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "Level 4 (Non-Urgent):" << setw(4) << CountL4 << " patients   Avg: " << setw(3) << avgL4 << " min";
if (avgL4 <= TARGET_L1 && CountL4 > 0) {cout << " [TARGET MET]\n";} else if (avgL4 > TARGET_L1) {cout << " [OVER TARGET]\n";} else {cout << " []\n";}
cout << "--------------------------------------\n";
cout << "TOTAL: " << (CountL1 + CountL2 + CountL3 + CountL4) 
<< " patients   Overall avg: " << setw(5) << (avgL1 + avgL2 + avgL3 + avgL4) / 4 << " min";

// print bar chart
for (int level = 1; level <= 4; level++) {
    double avgWait = 0;
    
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

    cout << "\nL: " << level;
    for (double star = 0; star < avgWait / 5; star++ ) {
        cout << "*";
    }
    if (avgWait > 0) {
    cout << " (" << avgWait << " minutes)";
    }
}
    cout << "\n" << endl;
}