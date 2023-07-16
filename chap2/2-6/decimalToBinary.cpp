#include <iostream>

using namespace std;

// If you’ve learned about binary numbers and how to convert from decimal
// to binary and the reverse, try writing programs to do those conversions with
// unlimited length numbers (but you can assume the numbers are small
// enough to be stored in a standard C++ int).



int DecimalToBinary(int numb) {
    if(numb / 2 == 0) {
    return numb % 2;
    }
   return 10 * DecimalToBinary(numb / 2) + numb % 2;
}


int main() {
    char digit = cin.get();
    int numb = 0;
    while(digit != 10) {
        numb = digit - '0' + numb * 10;
        digit = cin.get();
    }

    int result = DecimalToBinary(numb);
    cout << result << "\n";
    return 0;
}