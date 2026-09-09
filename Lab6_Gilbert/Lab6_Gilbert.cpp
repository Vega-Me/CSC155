#include <vector>
#include <iomanip>
#include <iostream>
#include <array>
#include <algorithm>
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
int highestP = 0;
string lowestN;
int lowestP = 100;

//Total and average points
int totalPoints = 0;
double averagePoints = 0;

//Prototypes
void calcAvg(double& averagePoints);
void calchighScorers(vector<string>& highScorers);
void displayTeams(int scoregrid[NUM_TEAMS][NUM_GAMES]);


int main() {

    //Part A
cout << "Number of players (3-10): ";
cin >> numPlayers;
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
    cout << lowestN << '\n';
    cout << lowestP << '\n';
    cout << highestN << '\n';
    cout << highestP << '\n';
    cout << fixed << setprecision(1) << averagePoints << '\n';
    cout << highScorers.size();




//=============================================================
    //Part B

    //  COLLECT DATA
    for (int i = 0; i < NUM_TEAMS; i++) {   //loops through rows
        
        cout << "\nEnter score for team " << teamNames[i] << "\n G1:";
        cin >> scoreGrid[i][0];

        for (int j = 1; j < NUM_GAMES; j++) {       //loops through columns
            cout << " G" << j + 1 << ": ";
            cin >> scoreGrid[i][j];
          }
    }

    // DISPLAYING DATA
    for (int i = 0; i < NUM_TEAMS; i++) {
        
        cout << teamNames[i] << setw(4) << scoreGrid[i][0];

        for (int j = 1; j < NUM_GAMES; j++) {
            cout << " G" << j + 1 << ": ";
            cin >> scoreGrid[i][j];
          }
    }


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


