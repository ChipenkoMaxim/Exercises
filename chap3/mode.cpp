#include <iostream>

using namespace std;


int main() {

    int ARR_SIZE = 12;
    int sourceArray[ARR_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    int modeArray[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++) modeArray[i] = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        modeArray[sourceArray[i] - 1] += 1;
    }

    int maxElem = 1;
    int countOfMaxElem = 0;
    for(int i = 0; i < ARR_SIZE; i++) {
        if(modeArray[i] > modeArray[maxElem - 1]) {
            countOfMaxElem = modeArray[i];
            maxElem = i + 1;
        }
    }

    cout << "Max Elem = " << maxElem << "\n" <<
    "Quantity of Max Elem = " << countOfMaxElem << "\n";
    return 0;
}