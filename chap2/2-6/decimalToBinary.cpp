#include <iostream>

using namespace std;

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