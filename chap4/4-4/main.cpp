#include <iostream>

// Change the implementation of our strings such that location[0] in the array
// stores the size of the array (and therefore location[1] stores the first actual
// character in the string), rather than using a null-character terminator.
// Implement each of the three functions, append, concatenate, and charactertAt,
// taking advantage of the stored size information whenever possible. Because
// we’ll no longer be using the null-termination convention expected by the
// standard output stream, you’ll need to write your own output function that
// loops through its string parameter, displaying the characters.



using namespace std;

typedef char* strType;

int strSize(strType arr) {
    int size = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        size++;
    }
    return size;
}

char characterAt(strType arr, int index) {
    return arr[index + 1];
}

void append(strType& arr, char symbol) {
    int oldSize = arr[0];
    int newSize = oldSize + 2;
    strType newStr = new char[newSize];
    newStr[0] = newSize - 1;
    for(int i = 1; i <= arr[0]; i++) {
        newStr[i] = arr[i];
    }
    newStr[oldSize + 1] = symbol;
    delete[] arr;
    arr = newStr;
}

void concatenate(strType& first, strType second) {
    int firstSize = first[0];
    int secondSize = second[0];
    int newSize = (firstSize + secondSize) + 1;

    strType newStr = new char[newSize];
    newStr[0] = newSize;

    for(int i = 1; i <= first[0]; i++) {
        newStr[i] = first[i];
    }
    for(int i = 1; i <= second[0]; i++) {
        newStr[firstSize + i] = second[i];
    }
    delete[] first;
    delete[] second;
    first = newStr;
}

void printStr(strType str) {
    for(int i = 1; i <= str[0]; i++) {
        cout << str[i];
    }
    cout << "\n";
}


int main() {
    strType str = new char[6];//{'H', 'e', 'l', 'l', 'o'};
    str[0] = 5;
    str[1] = 'H'; str[2] = 'e'; str[3] = 'l'; str[4] = 'l'; str[5] = 'o';
    //cout << str << "\n";
    printStr(str);
    //cout << strSize(str) << "\n";
    cout << (int)str[0] << "\n";
    cout << characterAt(str, 4) << "\n";
    append(str, ',');
    printStr(str);
    // cout << str << "\n";
    
    strType newStr = new char[8];
    newStr[0] = 7;
    newStr[1] =' ', newStr[2] = 'W', newStr[3]='o', newStr[4] = 'r', newStr[5] = 'l', newStr[6] = 'd', newStr[7] = '!';
    printStr(newStr);
    concatenate(str, newStr);
    // cout << str << "\n";
    printStr(str);
    cout << characterAt(str, 7) << "\n";
    return 0;
}