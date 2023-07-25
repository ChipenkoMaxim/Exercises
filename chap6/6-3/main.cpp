#include <iostream>

// Write a function that is passed an array of integers and a “target” number
// and that returns the number of occurrences of the target in the array. Solve
// the problem first using iteration, then recursion.



using namespace std;

void fillArr(int* arr, int N) {
    for(int i = 0; i < N; i++) {
        arr[i] = (rand() % 10) + 1;
    }
}

void printArr(int* arr, int N) {
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int calcTargetOccurrencesIterative(int* arr, int N, int target) {
    int numOfTarget = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] == target) numOfTarget++;
    }
    return numOfTarget;
}

int calcTargetOccurrencesRecursive(int* arr, int N, int target) {
    if(N == 0) return 0;
    int quantity = calcTargetOccurrencesRecursive(arr, N - 1, target);
    if(arr[N - 1] == target) quantity++;
    return quantity;
}


int main() {
    srand(time(NULL));
    int arr[10];
    fillArr(arr, 10);
    printArr(arr, 10);
    cout << "Num of 5s = " << calcTargetOccurrencesIterative(arr, 10, 5) << "\n";
    cout << "Num of 5s = " << calcTargetOccurrencesRecursive(arr, 10, 5) << "\n";
    return 0;
}