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

int fromDecimal(int numb, int base) {
    if(numb / base == 0) {
    return numb % base;
    }
   return 10 * fromDecimal(numb / base, base) + numb % base;
}




int main() {
    cout << "Enter source base: ";
    int sourceBase = 0;
    char tempSymb = cin.get();
    while (tempSymb != 10)
    {
        sourceBase = sourceBase * 10 + tempSymb - '0';
        tempSymb = cin.get();
    }
    cout << "\nEnter destination base: ";
    int destBase = 0;
    tempSymb = cin.get();
    while (tempSymb != 10)
    {
        destBase = destBase * 10 + tempSymb - '0';
        tempSymb = cin.get();
    }

    cout << "Enter source numb of base  " << sourceBase << ": ";
    int result = 0;
    if(sourceBase == 16) {
        //Hex to every other base
            //Hex to decimal
            //Decimal to every other base
        //Hex to decimal
        int power = 0;
        hexToDecimal(&power, &result);
        if(destBase != 10) {
            result = fromDecimal(result, destBase);
        }
    } else if(destBase == 16) {

    } else {

    }
    cout << result;
    return 0;
}