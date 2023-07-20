#include <iostream>

using namespace std;

// Design your own: Take a problem that you already know how to solve using
// an array but that is limited by the size of the array. Rewrite the code to remove
// that limitation using a dynamically allocated array.


int queryLength() {
    int length;
    cout << "Enter array length: ";
    cin >> length;
    cout << "\n";
    return length;
}

int generateRand(int upperLimit) {
    return rand() % (upperLimit + 1);
}

void fillArray(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        arr[i] = generateRand(100);
    }
}

void printArray(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int findMin(int* arr, int length) {
    int min = arr[0];
    for(int i = 1; i < length; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void fixedArrayMin() {
    int ARRAY_LENGTH = 10;
    int arr[ARRAY_LENGTH];
    fillArray(arr, ARRAY_LENGTH);
    cout << "Elements in fixed array: ";
    printArray(arr, ARRAY_LENGTH);
    int min = findMin(arr, ARRAY_LENGTH);
    cout << "Min for fixed array = " << min << "\n";
}

void dynamicArrayMin() {
    int ARRAY_LENGTH = queryLength();
    int* arr = new int[ARRAY_LENGTH];
    fillArray(arr, ARRAY_LENGTH);
    cout << "Elements in dynamic array: ";
    printArray(arr, ARRAY_LENGTH);
    int min = findMin(arr, ARRAY_LENGTH);
    cout << "Min for fixed array = " << min << "\n";
}

int main() {
    srand(time(NULL));
    fixedArrayMin();
    dynamicArrayMin();

    return 0;
}