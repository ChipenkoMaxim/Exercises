#include <iostream>
using namespace std;

// P R O B L E M : A S ID E WA Y S T R I A N GL E
// Write a program that uses only two output statements, cout << "#" and cout << "\n",
// to produce a pattern of hash symbols shaped like a sideways triangle:
// #
// ##
// ###
// ####
// ###
// ##
// #



// int main() {
//     int numOfHashes = 1;
//     int increment = 1;
//     for(int rows = 0; rows < 7; rows++) {
//         for(int colls = 0; colls < numOfHashes; colls++) {
//             cout << "#";
//         }
//         cout << "\n";
//         if(numOfHashes == 4) {
//             increment = -1;
//         }
//         numOfHashes += increment;
//     }
//     return 0;
// }

int main() {
    for(int rows = 0; rows < 7; rows++) {
        for(int colls = 0; colls < 4 - abs(4 - rows - 1); colls++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}