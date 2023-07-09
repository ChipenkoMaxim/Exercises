#include <iostream>
#include <math.h>
using namespace std;

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