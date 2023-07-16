#include <iostream>
#include <vector>
using namespace std;


void printArray(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void fillSourceArray(vector<int>* arr) {
    int num;
    cin >> num;
    while (num != -1)
    {
        (*arr).push_back(num);
        cin >> num;
    }
}

int findMode(vector<int> arr) {
    int highestFrequent = arr[0];
    int currentFrequent = arr[0];
    int currentQuantity = 1;
    int mostFrequentQuantity = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(currentFrequent == arr[i]) {
            currentQuantity++;
        } else {
            if(currentQuantity > mostFrequentQuantity) {
                highestFrequent = arr[i - 1];
                mostFrequentQuantity = currentQuantity;
                currentFrequent = arr[i];
                currentQuantity = 1;
            } else {
                currentFrequent = arr[i];
                currentQuantity = 1;
            }
        }
    }
    return highestFrequent;
}

void InsertionSort(vector<int>* arr, int size) {
    int start = 0;
    int end = size - 1;
    for(int i = start + 1; i <= end; i++) {
        for(int j = i; j > start && (*arr)[j - 1] > (*arr)[j]; j--) {
            int temp = (*arr)[j - 1];
            (*arr)[j - 1] = (*arr)[j];
            (*arr)[j] = temp;
        }
    }
}

int main() {
    vector<int> sourceArray;
    fillSourceArray(&sourceArray);
    cout << "Source array: ";
    printArray(sourceArray);
    InsertionSort(&sourceArray, sourceArray.size());
    int mode = findMode(sourceArray);
    cout << "Mode of array is: " << mode;
    
    return 0;
}