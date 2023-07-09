#include <iostream>

using namespace std;

void DecimalToHex(int numb) {
    if(numb / 16 == 0) {
        if(numb % 16 >= 10 && numb % 16 <= 15) {
            cout << char(numb % 16 + 55);
        } else {
            cout << numb % 16;
        }
        return;
    }
    DecimalToHex(numb / 16);
    if(numb % 16 >= 10 && numb % 16 <= 15) {
            cout << char(numb % 16 + 55);
        } else {
            cout << numb % 16;
        }
    return;
}


int main() {
    char digit = cin.get();
    int numb = 0;
    while(digit != 10) {
        numb = digit - '0' + numb * 10;
        digit = cin.get();
    }

    DecimalToHex(numb);
    return 0;
}