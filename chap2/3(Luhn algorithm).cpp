#include <iostream>
using namespace std;

// P R O B L E M : L U H N C H E C K S U M V A LI D A T I O N
// The Luhn formula is a widely used system for validating identification numbers. Using
// the original number, double the value of every other digit. Then add the values of the
// individual digits together (if a doubled value now has two digits, add the digits indi-
// vidually). The identification number is valid if the sum is divisible by 10.
// Write a program that takes an identification number of arbitrary length and
// determines whether the number is valid under the Luhn formula. The program must
// process each character before reading the next one.



int main() {
    int sum = 0;
    for(int digitNum = 1, digit = 0; ; digitNum++)
    {
        cin >> digit;
        if(digit <= 0 || digit >= 9) {
            break;
        }

        if (digitNum % 2 != 0)
        {
            sum += digit;
            continue;
        }

        int doubled = digit * 2;
        if(doubled > 9) {
            sum = sum + doubled % 10 + doubled / 10;
        }
        else {
            sum += doubled;
        }
    }
    if(sum % 10 == 0) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
    return 0;
}