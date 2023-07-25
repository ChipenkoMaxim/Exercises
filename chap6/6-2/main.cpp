#include <iostream>

// Consider an array representing a binary string, where every element’s data
// value is 0 or 1. Write a bool function to determine whether the binary string
// has odd parity (an odd number of 1 bits). Hint: Remember that the recursive
// function is going to return true (odd) or false (even), not the count of 1 bits.
// Solve the problem first using iteration, then recursion.


using namespace std;

void fillArr(bool* arr, int N) {
    for(int i = 0; i < N; i++) {
        arr[i] = (rand() % 2);
    }
}

void printArr(bool* arr, int N) {
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool hasOddParityIterative(bool* arr, int N) {
    int numOfOnes = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] == 1) numOfOnes++;
    }
    return numOfOnes % 2;
}

bool hasOddParityRecursive(bool* arr, int N) {
    if(N == 0) return 0;
    int current = arr[N - 1];
    int restArrResult = hasOddParityRecursive(arr, N - 1);
    return current ^ restArrResult;
}


int main() {
    srand(time(NULL));
    bool arr[10];
    fillArr(arr, 10);
    printArr(arr, 10);
    cout << hasOddParityIterative(arr, 10) << "\n";
    cout << hasOddParityRecursive(arr, 10) << "\n";
    return 0;
}