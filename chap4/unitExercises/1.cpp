// P R O BL E M : V A R I A BL E - L E N G T H S T R I N G M A N I PU LA T I O N
// Write heap-based implementations for three required string functions:
// append
//  This function takes a string and a character and appends the character
// to the end of the string.
// concatenate This function takes two strings and appends the characters of the
// second string onto the first.
// characterAt This function takes a string and a number and returns the character
// at that position in the string (with the first character in the string numbered zero).
// Write the code with the assumption that characterAt will be called frequently,
// while the other two functions will be called relatively seldom. The relative efficiency of
// the operations should reflect the calling frequency.

#include <iostream>

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
    return arr[index];
}

void append(strType& arr, char symbol) {
    int oldSize = strSize(arr);
    int newSize = oldSize + 2;
    strType newStr = new char[newSize];
    for(int i = 0; arr[i] != '\0'; i++) {
        newStr[i] = arr[i];
    }
    newStr[oldSize] = symbol;
    delete[] arr;
    arr = newStr;
}

void concatenate(strType& first, strType second) {
    int firstSize = strSize(first);
    int secondSize = strSize(second);
    int newSize = (firstSize + secondSize) + 1;

    strType newStr = new char[newSize];
    int index = 0;
    for(int i = 0; first[i] != '\0'; index++, i++) {
        newStr[index] = first[i];
    }
    for(int i = 0; second[i] != '\0'; index++, i++) {
        newStr[index] = second[i];
    }
    delete[] first;
    delete[] second;
    first = newStr;
}


int main() {
    strType str = new char[10]{'H', 'e', 'l', 'l', 'o'};
    cout << str << "\n";
    cout << strSize(str) << "\n";
    cout << characterAt(str, 4) << "\n";
    append(str, ',');
    cout << str << "\n";
    strType newStr = new char[10]{' ', 'W', 'o', 'r', 'l', 'd', '!'};
    concatenate(str, newStr);
    cout << str << "\n";
    cout << characterAt(str, 7);
    return 0;
}