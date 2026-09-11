#include <vector>
#include <iomanip>
#include <iostream>
#include <array>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_PLAYERS = 10;   // max players on roster
const int NUM_TEAMS   = 4;    // rows in game-score grid
const int NUM_GAMES   = 6;    // columns in game-score grid


string playerNames[MAX_PLAYERS];
string teamNames[] = {"HAWKS", "FALCONS", "EAGLES", "OWLS"};
int playerPts[MAX_PLAYERS];
int numPlayers;
vector<string> highScorers;
int scoreGrid[NUM_TEAMS][NUM_GAMES];

//Highest and lowest scorers
string highestN;
int highestP = -1000000;
string lowestN;
int lowestP = 1000000;

//Total and average points
int totalPoints = 0;
double averagePoints = 0;

string target;

//Prototypes
void calcAvg(double& averagePoints);
void calchighScorers(vector<string>& highScorers);
void displayTeams(int scoregrid[NUM_TEAMS][NUM_GAMES]);
int linearSearch(string playerNames[], int numPlayers, string target);
void findPeaks(int grid[][NUM_GAMES], int rows, int cols);


int main() {

    //Part A
do {                                                //asks for amount of players

cout << "Number of players (3-10): ";

if (!(cin >> numPlayers)) {

    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input";

} 
} while (numPlayers < 3 || numPlayers > 10);
cin.ignore();

    for (int i = 0; i < numPlayers; i++) {          //collect data
        cout << "Player " << (i+1) << " name: ";
        getline(cin, playerNames[i]);
        cout << "Season points: ";
        cin >> playerPts[i];
        cin.ignore();
    }
    for (int i = 0; i < numPlayers; i++) {          //total points
        totalPoints += playerPts[i];
    }
    for (int i = 0; i < numPlayers; i++) {          //lowest points
        if (playerPts[i] < lowestP) {
            lowestP = playerPts[i];
            lowestN = playerNames[i];
        }
    }
    for (int i = 0; i < numPlayers; i++) {          //highest points
        if (highestP < playerPts[i]) {
            highestP = playerPts[i];
            highestN = playerNames[i];
        }
    }

    //Necessary Functions
    calcAvg(averagePoints);
    calchighScorers(highScorers);

    //Fix this display

    cout << "\n=============================================\n";
    cout << "            HIGHEST AND LOWEST SCORERS\n";
    cout << "=============================================\n";
    cout << "LOWEST:   " << lowestN<< right << setw(5) << lowestP << '\n';
    cout << "HIGHEST:  " << highestN<< right << setw(5) << highestP << '\n';
    cout << "AVERAGE:  " << right << setw(5) << fixed << setprecision(1) << averagePoints << '\n';
    cout << "HIGH SCORERS: ";
    for (int i = 0; i < highScorers.size(); i++) {cout << highScorers[i] << '\n';}
    cout << "=============================================\n";



//==================================================================================================

    //Part B

    //  COLLECT DATA
    for (int i = 0; i < NUM_TEAMS; i++) {   //loops through rows
        
        cout << "\nEnter score for team " << teamNames[i] << "\n G1:";
        cin >> scoreGrid[i][0];

        for (int j = 1; j < NUM_GAMES; j++) {       //loops through columns
            cout << " G" << j + 1 << ": ";
            cin >> scoreGrid[i][j];
            cin.ignore();
          }
    }


// DISPLAYING DATA

    cout << "\n=============================================\n";
    cout << "             TOTALS AND BEST SCORES\n";
    cout << "=============================================\n";
    cout << "\n        ";

    for (int j = 0; j < NUM_GAMES; j++) {           //couts all the G#s
        cout << setw(4) << "G" << j + 1;
    }
    cout << '\n';

        for (int i = 0; i < NUM_TEAMS; i++) {
            cout << setw(11) << left << teamNames[i];

            for (int j = 0; j < NUM_GAMES; j++) {
                cout << setw(5) << scoreGrid[i][j];
            }
            cout << '\n';
    }    

    for (int i = 0; i < NUM_TEAMS; i++) {               // displays totals and best score 
        int totalT = 0;
        int bestS = scoreGrid[i][0];

        for (int j = 0; j < NUM_GAMES; j++) {
            totalT += scoreGrid[i][j];

            if (scoreGrid[i][j] > bestS) {
                bestS = scoreGrid[i][j];
            }
        }
        cout << left << setw(10) << teamNames[i] << "Total score: " << totalT << " Best Score: " << bestS << '\n';
    }

    for (int j = 0; j < NUM_GAMES; j++) {               //displays highest game
        int highestScore = scoreGrid[0][j];
        int highestTeam = 0;

        for (int i = 1; i < NUM_TEAMS; i++) {
            if (scoreGrid[i][j] > highestScore) {
                highestScore = scoreGrid[i][j];
                highestTeam = i;
            }
        }
        if (j == 0) {
            cout << "\n=============================================\n";
            cout << "         BEST TEAMS AND SCORES PER GAME\n";
            cout << "=============================================\n";
        }
        cout << "G" << j + 1
         << ": " << teamNames[highestTeam]
         << " - " << highestScore << '\n';
    }
    cout << "\n";

//==================================================================================================

//  Part C
    string target;
    int result;
    do {
    cout << "Fetch Player stats: ";
    cin >> target;
    result = linearSearch(playerNames, numPlayers, target);
    } while (result == -1);
    cout << playerNames[result] << ": " << playerPts[result] << " points\n";


//  C2
    cout << "\n--- Season Rankings (Highest to Lowest) ---";                              
    for (int i = 0; i < numPlayers - 1; i++) {          //stops before last

        int maxPlaceholder = i;

        for (int j = i + 1; j < numPlayers; j++) {      //checks last one with i + 1

            if (playerPts[j] > playerPts[maxPlaceholder]) {

                maxPlaceholder = j;

            }

        }

        swap(playerPts[i], playerPts[maxPlaceholder]);
        swap(playerNames[i], playerNames[maxPlaceholder]);

    }

    for (int i = 0; i < numPlayers; i++) {
        cout << "\n" << playerNames[i] << ": " << playerPts[i] << " points";
    }


//==================================================================================================

// Part D

    cout << "\n";
    findPeaks(scoreGrid, NUM_TEAMS, NUM_GAMES);

}








//---------------------------------------------------------------
//      Calculates the average

void calcAvg(double& averagePoints) {
    averagePoints = static_cast<double>(totalPoints) / numPlayers;
}
//---------------------------------------------------------------



//---------------------------------------------------------------
//      Calculates high scorers, people above the average

void calchighScorers(vector<string>& highScorers) {
    for (int i = 0; i < numPlayers; i++) {
        if (playerPts[i] > averagePoints) {
            highScorers.push_back(playerNames[i]);
        }
    }
}
//---------------------------------------------------------------


//---------------------------------------------------------------				
// Seaerches for target and gives stats				
int linearSearch(string playerNames[], int numPlayers, string target) {				
    for (int i = 0; i < numPlayers; i++) {				
        if (playerNames[i] == target) {				
        return i;				
        }							
    }				
    return -1;
}				
//---------------------------------------------------------------			


//---------------------------------------------------------------
//the monster function
void findPeaks(int grid[][NUM_GAMES], int teams, int games) {

    int count = 0;

    for (int t = 0; t < teams; t++ ) {                          //choose a row

        for (int g = 0; g < games; g++) {                       //choose a column

            bool isMax = true;
            bool isMin = true;

            for (int dt = -1; dt <= 1; dt++) {                      //neighbor 3x3 scan by row

                for (int dg = -1; dg <= 1; dg++) {                   //neighbor 3x3 scan by column

                    if (dt != 0 || dg != 0) {

                        int neighborT = t + dt;
                        int neighborG = g + dg;

                        if (neighborG >= 0 && neighborG < games && neighborT >= 0 && neighborT < teams) {

                            if (grid[t][g] <= grid[neighborT][neighborG]) {
                                isMax = false;
                            }

                            if (grid[t][g] >= grid[neighborT][neighborG]) {
                                isMin = false;
                            }

                        }

                    }

                } //dg close

            } //dt close

            if (isMax || isMin) {

                string category;
                count++;

                if ((t == 0 || t == teams - 1) && (g == 0 || g == games - 1)) {
                    category = "CORNER";
                }
                else if (t == 0 || t == teams - 1 || g == 0 || g == games - 1) {
                    category = "EDGE";
                }
                else {
                    category = "INTERIOR"; //crocidle alligator
                } 

                cout << "\nPeak " << count << right << setw(5) << grid[t][g] << setw(5) << " Row: " 
                << t << setw(5) << " Column: " << g << right << setw(15) << "Category: "
                << category << setw(8) << "Type: ";
                if (isMax) {
                    cout << "Local Max\n";
                }
                else {
                    cout << "Local Min\n";
                }

            }
            
        } //g close

    } //t close

}
//---------------------------------------------------------------


// Go through every cell in scoreGrid.
// For the current cell, compare its value against all valid neighboring cells.
// If it is greater than all neighbors, it is a local maximum.
// If it is less than all neighbors, it is a local minimum.
// If it is neither, don't display it.
// For every max/min you do find, display:
// its value
// its row and column index
// whether its location is CORNER, EDGE, or INTERIOR




















//pre lab
//
//excercise 1; gives me a error when trying to compile instead of running the program when I try 
//to reach position outside of the array

//excercise 2 
//if I trace the array the iterations would be 0, then 1, then -1. The final one would be negative 1 because it finally found the number 63.

//excercise 3 
//so for the selection sort array, the first pass would compare 65 to all of them, and then at the end sway 65 and 12. Then it would compare
//25 against 64 and 22 and then swap 22 and 25. So the array would look like {12, 22, 64, 25} at this point, then finally 64 would
//get swapped with 25. {12, 22, 25, 64}

//excercise 4
//the main difference is that vectors can add more columns to the selection whilst arrays are a fixed set usually. Also that vectors
//can have both columns and rows.

//excercise 5
//all the neighbors are, [0,1], [0,2], [0,3], [1,1], [1,3], [2,1], [2,2], [2,3]

//excercise 6
    // int grid[5][5] = {
    //     {1, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1},
    // };
    
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << setw(4) << grid[i][j];
    //     }
    // cout << '\n';


