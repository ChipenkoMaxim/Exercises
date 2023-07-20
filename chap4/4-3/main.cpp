#include <iostream>
#include <vector>

using namespace std;
typedef char* str;

// For our dynamically allocated strings, create a function replaceString that takes
// three parameters, each of type arrayString: source, target, and replaceText .
// The function replaces every occurrence of target in source with replaceText.
// For example, if source points to an array containing abcdabee, target points to
// ab, and replaceText points to xyz, then when the function ends, source should
// point to an array containing xyzcdxyzee.




int strSize(str arr) {
    int size = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        size++;
    }
    return size;
}

bool isTarget(str source, str target) {
    for(int i = 0; source[i] != '\0'; i++) {
        if(source[i] != target[i]) return false;
    }
    return true;
}

str substring(str& origStr, int start, int length) {
    if(start < 0 || length < 0) return NULL;
    if(strSize(origStr) < (start + length)) return NULL;
    str newStr = new char[length + 1];
    for(int i = 0; i < length; i++)
    {
        newStr[i] = origStr[start + i];
    }
    newStr[length] ='\0';
    return newStr;
}


void copyReplacement(vector<char>& newStr, str replacement) {
    for(int i = 0; replacement[i] != '\0'; i++) {
        newStr.push_back(replacement[i]);
    }
}

void replaceString(str& source, str target, str replacement) {
    int targetLength = strSize(target);
    int sourceLength = strSize(source);
    vector<char> newStr;
    for(int i = 0; i < sourceLength; i++) 
    {
        if(source[i] == target[0]) {
            str probableTarget = substring(source, i, targetLength);
            if(isTarget(probableTarget, target)) {
                copyReplacement(newStr, replacement);
                i += (targetLength - 1);
            }
            else {
                newStr.push_back(source[i]);   
            }
            delete[] probableTarget;
        }
        else {
             newStr.push_back(source[i]);
        }
    }

    int newLength = newStr.size();
    str replacingStr = new char[newLength + 1];
    for(int i = 0; i < newLength; i++) {
        replacingStr[i] = newStr[i];
    }
    replacingStr[newLength] = '\0';
    delete[] source;
    source = replacingStr;
    cout << "\n";
}


int main() {
    int stringLength = 15;
    str origStr = new char[stringLength]{'!'};
    str target = new char[stringLength]{'!'};
    str replaceStr = new char[stringLength]{'M', 'a', 'x'};
    // str origStr = new char[stringLength]{'a', 'b', 'c', 'd', 'a', 'b', 'e', 'e'};
    // str target = new char[stringLength]{'a', 'b'};
    // str replaceStr = new char[stringLength]{'x', 'y', 'z'};
    cout << "Before state of string: " << origStr << "\n";
    replaceString(origStr, target, replaceStr);
    cout << "After state of string: " << origStr << "\n";
    return 0;
}