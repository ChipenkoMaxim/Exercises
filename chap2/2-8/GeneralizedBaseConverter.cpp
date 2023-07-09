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

void toDecimal(int* power, int* sum, int base) {
    char digit = cin.get();
    if(digit == 10) {return;}
    toDecimal(power, sum, base);
    *sum += ((digit - '0') * pow(base, *power));
    *power += 1;
    
    return;
}

int fromDecimal(int numb, int base) {
    if(numb / base == 0) {
    return numb % base;
    }
   return 10 * fromDecimal(numb / base, base) + numb % base;
}

void decimalToHex(int numb) {
    if(numb / 16 == 0) {
        if(numb % 16 >= 10 && numb % 16 <= 15) {
            cout << char(numb % 16 + 55);
        } else {
            cout << numb % 16;
        }
        return;
    }
    decimalToHex(numb / 16);
    if(numb % 16 >= 10 && numb % 16 <= 15) {
            cout << char(numb % 16 + 55);
        } else {
            cout << numb % 16;
        }
    return;
}



// 16 to 2 B1+ 52+ 32+
// 16 to 10 B1+ 52+ 32+
// 2 to 16 10111 10010 11111 +++
// 2 to 10 10111 10010 11111 +++
// 10 to 16 31254 52365 421261 + 
// 10 to 2 31 55 42
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
        cout << result;
    } else if(destBase == 16) {
        if(sourceBase == 10) {
            char digit = cin.get();
            int numb = 0;
            while(digit != 10) {
            numb = digit - '0' + numb * 10;
            digit = cin.get();
            }
            decimalToHex(numb);
        }
        else {
            int power = 0;
            toDecimal(&power, &result, sourceBase);
            decimalToHex(result);
        }
    } else {
        if(sourceBase == 10) {
            char digit = cin.get();
            int numb = 0;
            while(digit != 10) {
            numb = digit - '0' + numb * 10;
            digit = cin.get();
            }
            result = fromDecimal(numb, destBase);
        }
        else {
            int power = 0;
            toDecimal(&power, &result, sourceBase);
            result = fromDecimal(result, destBase);
        }
        cout << result;
    }
    return 0;
}