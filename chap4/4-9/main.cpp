#include <iostream>

//Imagine a linked list where instead of the node storing a character, the node
// stores a digit: an int in the range 0–9. We could represent positive numbers
// of any size using such a linked list; the number 149, for example, would be a
// linked list in which the first node stores a 1, the second a 4, and the third and
// last a 9. Write a function intToList that takes an integer value and produces a
// linked list of this sort. Hint: You may find it easier to build the linked list
// backward, so if the value were 149, you would create the 9 node first.


using namespace std;

struct digitNode {
    int digit;
    digitNode* nextNode = NULL;
};

typedef digitNode* Number;

void initNode(digitNode*& node, int digit) {
    node = new digitNode;
    node->digit = digit;
    node->nextNode = NULL;
}

void append(Number& numb, int digit) {
    if(numb == NULL) {
        initNode(numb, digit);
    }
    else {
        digitNode* newNode = NULL;
        initNode(newNode, digit);
        newNode->nextNode = numb;
        numb = newNode;
    }
}


void inputNumber(Number& numb) {
    char inputChar = cin.get();
    while (inputChar != 10)
    {
        int digit = inputChar - '0';
        append(numb, digit);
        inputChar = cin.get();
    }
}

void printNumber(Number numb) {
    if(numb == NULL) {
        return;
    }
    printNumber(numb->nextNode);
    cout << numb->digit;
}

int main() {
    Number numb = NULL;
    inputNumber(numb);
    printNumber(numb);
    return 0;
}