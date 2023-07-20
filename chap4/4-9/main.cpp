#include <iostream>

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