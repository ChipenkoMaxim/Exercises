#include <iostream>

// Add a function to the linked-list string implementation called removeChars to
// remove a section of characters from a string based on the position and length.
// For example, removeChars(s1, 5, 3) would remove the three characters starting
// at the fifth character in the string. Make sure the removed nodes are properly
// deallocated.

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

void concatenate(String first, String second) {
    while (first->nextNode)
    {
        first = first->nextNode;
    }
    
    while (second)
    {
        append(first, second->letter);
        second = second->nextNode;
    }
}

void removeChars(String& str, int start, int length) {
    if(start == 1) {
        for(int i = 0; i < length; i++) {
            charNode* newHead = str->nextNode;
            delete str;
            str = newHead;
        }
    } else {
        charNode* prevNode = str;
        charNode* currNode = str->nextNode;
        for(int i = 2; i < start; i++) {
            prevNode = currNode;
            currNode = currNode->nextNode;
        }

        for(int i = 0; i < length; i++) {
            prevNode->nextNode = currNode->nextNode;
            delete currNode;
            currNode = prevNode->nextNode;
        }
    }
}

int main() {
    String firstStr = NULL;
    inputString(firstStr);
    cout << "First String is: ";
    printString(firstStr);
    removeChars(firstStr, 1, 7);
    printString(firstStr);
    return 0;
}