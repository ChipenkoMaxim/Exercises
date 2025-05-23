#include <iostream>
// Write a function to compute the sum of just the positive numbers in an array
// of integers. First, solve the problem using iteration. Then, using the technique
// shown in this chapter, convert your iterative function to a recursive function.

using namespace std;

void fillArr(int* arr, int N) {
    for(int i = 0; i < N; i++) {
        arr[i] = (rand() % 100) + 1;
        if(rand() % 2) arr[i] *= -1;
    }
}

void printArr(int* arr, int N) {
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int calcSumOfPositiveIter(int* arr, int N) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int calcSumOfPositiveRecur(int* arr, int N) {
    if(N == 0) return 0;
    int sum = calcSumOfPositiveRecur(arr, N - 1);
    if(arr[N - 1] > 0) sum += arr[N - 1];
    return sum;
}



int main() {
    srand(time(NULL));
    int arr[10];
    fillArr(arr, 10);
    printArr(arr, 10);
    cout <<  calcSumOfPositiveIter(arr, 10) << "\n";
    cout << calcSumOfPositiveRecur(arr, 10) << "\n";
    return 0;
}