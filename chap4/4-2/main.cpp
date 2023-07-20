#include <iostream>

using namespace std;

typedef char* str;

int strSize(str arr) {
    int size = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        size++;
    }
    return size;
}


str substring(str& origStr, int start, int length) {
    if(start < 0 || length < 0) return NULL;
    if(strSize(origStr) < (start + length)) return NULL;
    str newStr = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        newStr[i] = origStr[start + i];
    }
    return newStr;
}


int main() {
    int stringLength = 20;
    str origStr = new char[stringLength]{'H', 'e', 'l', 'l', 'o', ',', 'W', 'o', 'r', 'l', 'd', '!'};
    str subStr = substring(origStr, 5, 1);
    cout << "Original string = " << origStr << "\n";
    cout << "Substring = " << subStr << "\n";
    return 0;
}