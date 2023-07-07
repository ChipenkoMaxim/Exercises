#include <iostream>
using namespace std;

int main() {
    char digit;
    digit = cin.get();
    if(digit < '0' || digit > '9') {
        cout << "Error, enter a number" << endl;
        return 0;
    }

    int sum = digit - 48;
    cout << sum << endl;
    return 0;
}