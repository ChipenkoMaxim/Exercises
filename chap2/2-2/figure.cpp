#include <iostream>

using namespace std;

// Or how about:
//    ##
//   ####
//  ######
// ########
// ########
//  ######
//   ####
//    ##


int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4 - i; j++) {
            cout << " ";
        }
        for(int j = 0; j <  2 * (i + 1); j++) {
            cout << "#";
        }
        cout << "\n";
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i + 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 8 - 2 * i; j++) {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}