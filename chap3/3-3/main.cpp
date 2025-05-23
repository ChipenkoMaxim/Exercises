#include <iostream>

using namespace std;

// Write a bool function that is passed an array and the number of elements in
// that array and determines whether the data in the array is sorted. This should
// require only one pass!


bool isSortedByIncreasingOrder(int* arr, int num) {
    for(int i = 0; i < num - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isSortedByDecreasingOrder(int* arr, int num) {
    for(int i = 0; i < num - 1; i++) {
        if(arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isSorted(int* arr, int num) {
    return isSortedByDecreasingOrder(arr, num) ||
    isSortedByIncreasingOrder(arr, num);
}


int main() {
    int arr[10] = {1, 4, 2, 3, 1 ,1 ,1 ,1, 3, 4};
    if(isSorted(arr, 10)) {
        cout << "Array is sorted\n";
    } else {
        cout << "Array is not sorted\n";
    }
    return 0;
}