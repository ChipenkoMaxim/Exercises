#include <iostream>

using namespace std;


int comparator(const void* fist, const void* second) {
    int* A = (int*)(fist);
    int* B = (int*)(second);

    return *A - *B;
}


int main() {

    int ARR_SIZE = 12;
    int sourceArray[ARR_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};


    qsort(sourceArray, ARR_SIZE, sizeof(int), comparator);

    for(int i = 0; i < ARR_SIZE; i++) cout << sourceArray[i] << " ";
    int currElem = sourceArray[0];
    int maxElem = 0;
    int currCount = 1;
    int countOfMaxElem = 0;
    for(int i = 1; i < ARR_SIZE; i++) {
        if(sourceArray[i] == currElem) {
            currCount++;
        } else if(countOfMaxElem < currCount) {
            countOfMaxElem = currCount;
            maxElem = currElem;
            currElem = sourceArray[i];
            currCount = 1;
        } else {
            currElem = sourceArray[i];
            currCount = 1;
        }
    }


    cout << "\nMax Elem = " << maxElem << "\n" <<
    "Quantity of Max Elem = " << countOfMaxElem << "\n";
    return 0;
}