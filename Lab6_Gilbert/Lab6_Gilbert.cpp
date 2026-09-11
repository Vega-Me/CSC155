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
vector<int> seasonScores;
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
int linearSearch(string names[], int pts[], int n, string target);
void findPeaks(int grid[][NUM_GAMES], int rows, int cols);
void selectionSort(string names[], int pts[], int n);


int main() {

    //Part A
do {                                                //asks for amount of players

cout << "Number of players (3-10): ";

if (!(cin >> numPlayers)) {

    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input\n";

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
    cout << "TOTAL POINTS: " << totalPoints << '\n';
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
        seasonScores.push_back(totalT);
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

    cout << "\n=============================================\n";
    cout << "               TEAM PLACEMENTS\n";
    cout << "=============================================\n";
    cout << "Rank  Team      Total Score\n";
    for (int i = 0; i < NUM_TEAMS - 1; i++) {
        int maxPlaceholder = i;

        for (int j = i + 1; j < NUM_TEAMS; j++) {
            
            if (seasonScores[j] > seasonScores[maxPlaceholder]) {
                maxPlaceholder = j;
            }

        }

        swap(seasonScores[i], seasonScores[maxPlaceholder]);
        swap(teamNames[i], teamNames[maxPlaceholder]);

    }
    for (int i = 0; i < NUM_TEAMS - 1; i++) {
        
        if (seasonScores[i] == seasonScores[i + 1]) {

            cout << "TIE BETWEEN: " << teamNames[i] << " AND " << teamNames[i + 1];

        }
    }
    for (int i = 0; i < NUM_TEAMS; i++) {
        cout << right << setw(4) << i + 1 << "   " << left << setw(10) << teamNames[i] << seasonScores[i] << "points!" << '\n';
    }
    cout << "=============================================\n";


//==================================================================================================

//  Part C1
    string target;
    int result;
   
    cout << "Pick a player to view stats for: " << endl;
        for (int i = 0; i < numPlayers; i++) {
            cout << playerNames[i] << "\n";
        }
    cout << "\n" << endl;
    getline(cin, target);
    result = linearSearch(playerNames, playerPts, numPlayers, target);
    
    if (result == -1) {
        cout << "Player not found.\n";
    }
    else {
    cout << playerNames[result] << ": " << playerPts[result] << " points\n";
    }

//  C2

selectionSort(playerNames, playerPts, numPlayers);


//==================================================================================================

// Part D
    cout << "\n=============================================";
    findPeaks(scoreGrid, NUM_TEAMS, NUM_GAMES);
    cout << "\n=============================================\n";
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
int linearSearch(string playerNames[], int pts[], int numPlayers, string target) {				
    for (int i = 0; i < numPlayers; i++) {				
        if (playerNames[i] == target) {				
        return i;				
        }							
    }				
    return -1;
}				
//---------------------------------------------------------------			


//---------------------------------------------------------------
void selectionSort(string playerNames[], int playerPts[], int numPlayers) {
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
        cout << "\n" << right << setw(18) << i + 1 << " " << playerNames[i] << ": " << playerPts[i] << " points";
    }
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
            int neighborcount = 0;

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

                            neighborcount++;

                        }

                    }

                } //dg close

            } //dt close

            if (isMax || isMin) {

                string category;
                count++;

                if (neighborcount == 3) {
                    category = "CORNER";
                }
                else if (neighborcount == 5) {
                    category = "EDGE";
                }
                else {
                    category = "INTERIOR"; //crocidle alligator
                } 

                cout << "\nPeak " << count << ", " << "Points: " << right << setw(5) << grid[t][g] << ", "
                << " Row: " << t << " Column: " << g << right << setw(15) << "Category: "
                << setw(10) << category << setw(8) << "Type: ";
                if (isMax) {
                    cout << "Local Max";
                }
                else {
                    cout << "Local Min";
                }

            }
            
        } //g close

    } //t close

}
//---------------------------------------------------------------












//              PRE LAB
//
//excercise 1; gives me a error when trying to compile instead of running the program when I try 
//to reach position outside of the array

//excercise 2 
//if I trace the array the iterations would be 0, then 1, then -1. The final one would be negative 1 because it finally found the number 63.
//Devon Okafor → index 2
//Alex Johnson → -1

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









//                                  POST LAB

// Excercise 1
// Number of players (3-10): 5
// Player 1 name: Jordan Reyes
// Season points: 412
// Player 2 name: Maya Chen
// Season points: 388
// Player 3 name: Devon Okafor
// Season points: 321
// Player 4 name: Priya Singh
// Season points: 298
// Player 5 name: Luca Ferrara
// Season points: 245

// =============================================
//             HIGHEST AND LOWEST SCORERS
// =============================================
// LOWEST:   Luca Ferrara  245
// HIGHEST:  Jordan Reyes  412
// AVERAGE:  332.8
// HIGH SCORERS: Jordan Reyes
// Maya Chen
// =============================================

// Enter score for team HAWKS
//  G1:72
//  G2: 68
//  G3: 81
//  G4: 55
//  G5: 90
//  G6: 77

// Enter score for team FALCONS
//  G1:61
//  G2: 74
//  G3: 69
//  G4: 88
//  G5: 52
//  G6: 83

// Enter score for team EAGLES
//  G1:85
//  G2: 59
//  G3: 76
//  G4: 71
//  G5: 
// 64
//  G6: 92

// Enter score for team OWLS
//  G1:48
//  G2: 83
//  G3: 65
//  G4: 79
//  G5: 88
//  G6: 60

// =============================================
//              TOTALS AND BEST SCORES
// =============================================

//            G1   G2   G3   G4   G5   G6
// HAWKS      72   68   81   55   90   77   
// FALCONS    61   74   69   88   52   83   
// EAGLES     85   59   76   71   64   92   
// OWLS       48   83   65   79   88   60   
// HAWKS     Total score: 443 Best Score: 90
// FALCONS   Total score: 427 Best Score: 88
// EAGLES    Total score: 447 Best Score: 92
// OWLS      Total score: 423 Best Score: 88

// =============================================
//          BEST TEAMS AND SCORES PER GAME
// =============================================
// G1: EAGLES - 85
// G2: OWLS - 83
// G3: HAWKS - 81
// G4: FALCONS - 88
// G5: HAWKS - 90
// G6: EAGLES - 92

// Fetch Player stats: Devon Okafor
// Devon Okafor: 321 points

// --- Season Rankings (Highest to Lowest) ---
// Jordan Reyes        : 412 points
// Maya Chen           : 388 points
// Devon Okafor        : 321 points
// Priya Singh         : 298 points
// Luca Ferrara        : 245 points

// Peak 1, Points:    90,  Row: 0 Column: 4     Category: EDGE  Type: Local Max
// Peak 2, Points:    52,  Row: 1 Column: 4     Category: INTERIOR  Type: Local Min
// Peak 3, Points:    85,  Row: 2 Column: 0     Category: EDGE  Type: Local Max
// Peak 4, Points:    92,  Row: 2 Column: 5     Category: EDGE  Type: Local Max
// Peak 5, Points:    48,  Row: 3 Column: 0     Category: CORNER  Type: Local Min
// Peak 6, Points:    60,  Row: 3 Column: 5     Category: CORNER  Type: Local Min


// Excercise 2
// Fetch Player stats: Devon Okafor
// Devon Okafor: 321 points
// 
// IF I input the unkown roster, my program returns "Invalid Input"


//Excercise 3
// Sort Sync Verification
// After sorting by points descending, verify that each name still appears next to the correct points total. 
// Then add a player named "Test Player" with 412 points (a tie with Jordan Reyes).
//  Run the sort again. Whose name appears first in a tie? 
//  Record the result and explain in a comment whether your selection sort is stable (preserves original order for equal elements) or unstable, and why it matters.

//answer:
//When I add Test Player with 412 points to the two arrays what happens is that when they initially cross each other
// Test Player > Jordan Reyes would end up being false. So Jordan Reyes remains at position 0 after the final
//sorting process. My selection process is unstable but preserves the original order, the reason why
//being unstable or stable matters is because we want to account for a wide variety of scenarios that can happen
//otherwise we'll have bugs and errors that will go unoticed, and at scale that can be the cause of an entire program's failure.









//                          CREATIVE FINAL FEATURE
// What feature did you add and which part of the lab does it extend?
//      So I redid the neighbor checking to create a counter that simplifies filtering whether or not a peak is a corner
//      edge, or interior. I also added a sorting to the teams and then ranked them by best performing temas. 
//      Giving ranks based on how well they did in the season.
// What did you learn from the AI conversation about boundary handling or algorithm design that shaped your implementation?
//      I learned that there are always better ways to do things, whilst talking to the ai 
//      I kind of realized that instead of filtering the positions to get the catgeorys. That I can have a well placed counter
//      tell me exactly how many neighbors surrounded the position in the array. I also wanted to reimplement a learned
//      use from the lab so what I did was reuse the ranking loops for ranking each team during the season (games played/columns).
// Why did you choose this feature over others you considered?
//      I choose both these features because I like thinking about how systems can be better optomized, I also wanted to hammer down
//      the pre-existing lesson of using the for loops to rank array positions.
// What would happen to your feature's correctness if you changed NUM_TEAMS or NUM_GAMES? Is your implementation flexible enough to handle different grid sizes?
//      Nothing would really happen, I think it's scaleable with grid sizes since I used NUM_TEAMS and NUM_GAMES from the 
//      procedure. I also now understand the importance of using a declared variable in the beggining as a array size
//      because otherwise I would've had to declare the array size every single time. I would have to change
//      teamNames though. That is the only thing that isn't automatic which would probabl be fixed
//      with a for loop to get the names and relate them to points.
// 
