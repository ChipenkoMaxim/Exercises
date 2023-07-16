#include <iostream>
#include <math.h>
using namespace std;

// If you’ve learned about binary numbers and how to convert from decimal
// to binary and the reverse, try writing programs to do those conversions with
// unlimited length numbers (but you can assume the numbers are small
// enough to be stored in a standard C++ int).


void binaryToDecimal(int* power, int* sum) {
    char digit = cin.get();
    if(digit == 10) {return;}
    binaryToDecimal(power, sum);
    *sum += ((digit - '0') * pow(2, *power));
    *power += 1;
    return;
}


int main() {
    int counter = 0;
    int sum = 0;
    binaryToDecimal(&counter, &sum);
    cout << sum << "\n";
    return 0;
}