#include <iostream>
using namespace std;

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