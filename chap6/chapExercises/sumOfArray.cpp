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


int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = calcSumIterative(arr, 10);
    cout << sum << "\n";
    return 0;
}