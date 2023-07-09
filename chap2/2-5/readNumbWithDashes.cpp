#include <iostream>

using namespace std;

int main() {
    //978-0-306-40615-7
    char digit = cin.get();
    int numeric;
    while(digit != 10) {
        if(digit == '-') {}// Do nothing;
        else { 
            numeric = digit - '0';
            cout << numeric;
        }
        digit = cin.get();
    }
    cout << "\n";
    return 0;
}