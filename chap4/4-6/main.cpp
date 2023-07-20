#include <iostream>
// Let’s create an implementation for strings that uses a linked list of characters
// instead of dynamically allocated arrays. So we’ll have a linked list where the
// data payload is a single char; this will allow strings to grow without having to re-
// create the entire string. We’ll start by implementing the append and characterAt
// functions.

using namespace std;

struct charNode {
    char letter;
    charNode* nextNode = NULL;
};

typedef charNode* String;

void initNode(charNode*& node, char newChar) {
    node = new charNode;
    node->letter = newChar;
    node->nextNode = NULL;
}

void append(String& str, char newChar) {
    if(str == NULL) {
        initNode(str, newChar);
    }
    else {
        charNode* currNode = str;
        while (currNode->nextNode)
        {
            currNode = currNode->nextNode;
        }
        initNode(currNode->nextNode, newChar);
    }
}


void inputString(String& str) {
    char inputChar = cin.get();
    while (inputChar != 10)
    {
        append(str, inputChar);
        inputChar = cin.get();
    }
}

void printString(String str) {
    while (str)
    {
        cout << str->letter;
        str = str->nextNode;
    }
    cout << "\n";
}

char characterAt(String str, int index) {
    while (str && index)
    {
        str = str->nextNode;
        index--;
    }
    if(str == NULL) return '\0';
    return str->letter;
}

int main() {
    String str = NULL;
    inputString(str);
    printString(str);
    cout << characterAt(str, 1) << "\n";
    return 0;
}