#include <iostream>
// Following up on the previous exercise, implement the concatenate function.
// Note that if we make a call concatenate(s1, s2), where both parameters are
// pointers to the first nodes of their respective linked lists, the function should
// create a copy of each of the nodes in s2 and append them to the end of s1.
// That is, the function should not simply point the next field of the last node in
// s1’s list to the first node of s2’s list.

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

int main() {
    String firstStr = NULL;
    inputString(firstStr);
    String secondStr = NULL;
    inputString(secondStr);
    cout << "First String is: ";
    printString(firstStr);
    cout << "Second String is: ";
    printString(secondStr);
    concatenate(firstStr, secondStr);
    cout << "Concatenated first String is: ";
    printString(firstStr);
    return 0;
}