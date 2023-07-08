#include <iostream>

using namespace std;

int main() {
    for(int i = 3; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        
        for(int j = 0; j < i + 1; j++) {
            cout <<"#";
        }

        for(int j = 0; j < 14 - 2 * (i + 1) - 2 * i; j++) {
            cout << " ";
        }

        for(int j = 0; j < i + 1; j++) {
            cout <<"#";
        }
        cout << "\n";
    }
    return 0;
}