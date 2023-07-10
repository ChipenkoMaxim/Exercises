#include <iostream>

using namespace std;

void InsertionSort(int* arr, int size) {
    int start = 0;
    int end = size - 1;
    for(int i = start + 1; i <= end; i++) {
        for(int j = i; j > start && arr[j - 1] > arr[j]; j--) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}


int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Unsorted: ";
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    InsertionSort(arr, 10);
    cout << "Sorted: ";
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
}