// ask for integer until 7
// count incorrect entries until 7

#include <iomanip>
#include <iostream>
using namespace std;

int number;
int notcount = 0;

int main (){

    do {
    cout << "Enter the number 7: ";
    cin >> number;

    if (number != 7) {
        notcount++;
    }

    } while (number != 7);

    cout << notcount;
}

