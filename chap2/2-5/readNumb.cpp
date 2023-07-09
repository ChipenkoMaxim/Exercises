#include <iostream>

using namespace std;

int main() {
    char digit = cin.get();
    int numeric;
    while(digit != 10) {
        numeric = digit - '0';
        cout << numeric;
        digit = cin.get();
    }
    cout << "\n";
    return 0;
}