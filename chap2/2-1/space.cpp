#include <iostream>

using namespace std;

int main() {
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