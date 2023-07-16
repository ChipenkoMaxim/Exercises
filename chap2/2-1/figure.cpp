#include <iostream>

using namespace std;

// Using the same rule as the shapes programs from earlier in the chapter (only
// two output statements—one that outputs the hash mark and one that outputs
// an end-of-line), write a program that produces the following shape:
// ########
//  ######
//   ####
//    ##



int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8 - 2 * i; j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}