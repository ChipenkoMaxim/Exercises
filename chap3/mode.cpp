#include <iostream>

using namespace std;


int main() {

    int ARR_SIZE = 10;
    int sourceArray[ARR_SIZE] = {1, 5, 3, 2, 1, 1, 3, 5, 4 ,3};
    int modeArray[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++) modeArray[i] = 0;

    for(int i = 0; i < ARR_SIZE; i++) {
        modeArray[sourceArray[i] - 1] += 1;
    }

    int maxElem = 0;
    int countOfMaxElem = 0;
    for(int i = 0; i < ARR_SIZE; i++) {
        if(modeArray[i] > countOfMaxElem) {
            countOfMaxElem = modeArray[i];
            maxElem = modeArray[i];
        }
    }

    cout << "Max Elem = " << maxElem << "\n" <<
    "Quantity of Max Elem = " << countOfMaxElem << "\n";
    return 0;
}