#include <iostream>
using namespace std;

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