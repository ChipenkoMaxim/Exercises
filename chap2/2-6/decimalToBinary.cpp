#include <iostream>

using namespace std;

void DecimalToBinary(int numb) {
    if(numb / 2 == 0) {
    cout << numb % 2;
    return;
    }
   DecimalToBinary(numb / 2);
   cout << numb % 2;
   return;
}


int main() {
    char digit = cin.get();
    int numb = 0;
    while(digit != 10) {
        numb = digit - '0' + numb * 10;
        digit = cin.get();
    }

    DecimalToBinary(numb);
    return 0;
}