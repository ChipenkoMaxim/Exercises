#include <iostream>

using namespace std;

// If you like the Luhn formula problem, try writing a program for a different
// check-digit system, like the 13-digit ISBN system. The program could take an
// identification number and verify it or take a number without its check digit
// and generate the check digit.



int main() {
    //EX: 978-0-306-40615 without check num or 978-0-306-40615-7 with it
    //Read each char in cycle
    //Translate digit char to int form
    //Track running sum and digit count
    //Multiply every odd num on 1 and every even on 3
    //Store last read digit
    //If digit count equal 12, then calculate check digit by formula 0 <= 10 - (sum mod 10) <= 9
    //If digit count equal 13, then subtract last digit from sum and calculate check digit by formula mentioned above
        //Compare result with last digit (number is valid if result equal to last digit(check digit))
    char digit = cin.get();
    int lastDigit;
    int sum = 0;
    int digitCount = 0;
    while(digit != 10) {
        if(digit == '-') {}// Do nothing;
        else { 
            lastDigit = digit - '0';
            if(digitCount % 2 == 1) sum += lastDigit * 3;
            else sum += lastDigit;
            digitCount++;
        }
        digit = cin.get();
    }

    // cout << "Sum = " << sum << "\n";
    // cout << "Last digit = " << lastDigit << "\n";
    // cout << "Digit count = " << digitCount << "\n";

    if(digitCount == 12) {
        int checkDigit = 10 - (sum % 10);
        cout << "CheckDigit = " << checkDigit << "\n";
    } else if(digitCount == 13) {
        int checkDigit = 10 - ((sum - lastDigit) % 10);
        if(checkDigit == lastDigit) cout << "ISBN is valid" << "\n";
        else cout << "ISBN is invalid" << "\n";
    }
    else cout << "ISBN is invalid" << "\n";
    return 0;
}