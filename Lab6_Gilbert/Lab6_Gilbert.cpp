#include <vector>
#include <iomanip>
#include <iostream>
#include <array>
using namespace std;


int main() {
    const int NUMB = 5;
    int nums[NUMB] = {10, 20, 30, 40, 50};

    for (int i = NUMB - 1; i >= 0; i--) {
        cout << nums[i] << '\n'; 
    }
}