#include <iostream>
using namespace std;

// P R O BL E M : H A L F O F A S Q U A R E
// Write a program that uses only two output statements, cout << "#" and cout << "\n",
// to produce a pattern of hash symbols shaped like half of a perfect 5 x 5 square (or a
// right triangle):
// #####
// ####
// ###
// ##
// #


int main() {

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 - i; j++) {
            cout << '#';
        }
        cout << "\n";
    }
    return 0;
}