#include <iostream>

// Write a recursive function that is given an array of integers and the size of the array
// as parameters. The function returns the sum of the integers in the array.


using namespace std;

int calcSumIterative(int* arr, int N) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

int calcSumRecursive(int* arr, int N) {
    if(N == 0) return 0;
    return arr[N - 1] + calcSumRecursive(arr, N - 1);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = calcSumIterative(arr, 10);
    cout << sum << "\n";

    int sum1 = calcSumRecursive(arr, 10);
    cout << sum1 << "\n";
    return 0;
}