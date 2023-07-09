#include <iostream>
#include <math.h>
using namespace std;

void hexToDecimal(int* power, int* sum) {
    char digit = cin.get();
    if(digit == 10) {return;}
    hexToDecimal(power, sum);
    if(digit >= 'A' && digit <= 'F') {
        *sum += ((digit - 55) * pow(16, *power));
        *power += 1;
    }
    else {
        *sum += ((digit - '0') * pow(16, *power));
        *power += 1;
    }
    return;
}


int main() {
    int counter = 0;
    int sum = 0;
    hexToDecimal(&counter, &sum);
    cout << sum << "\n";
    return 0;
}