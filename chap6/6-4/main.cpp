#include <iostream>

// Design your own: Find a problem processing a one-dimension array that you
// have already solved or that is trivial for you at your current skill level, and
// solve the problem (or solve it again) using recursion.

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

int findMin(int* arr, int N) {
    int min = arr[0];
    for(int i = 1; i < N; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int findMinRecur(int* arr, int N) {
    if(N == 1) return arr[N - 1];
    int min = findMin(arr, N - 1);
    if(arr[N - 1] < min) min = arr[N - 1];
    return min;
}


int main() {
    srand(time(NULL));
    int arr[10];
    fillArr(arr, 10);
    printArr(arr, 10);
    cout << "Min = " << findMin(arr, 10) << "\n";
    cout << "Min = " << findMinRecur(arr, 10) << "\n";
    return 0;
}