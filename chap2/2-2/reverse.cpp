#include <iostream>

using namespace std;

int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4 - i; j++) {
            cout << " ";
        }
        for(int j = 0; j <  8 - (8 - (i + 1) * 2); j++) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}