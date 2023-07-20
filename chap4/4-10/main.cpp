#include <iostream>

// For the digit list of the previous exercise, write a function that takes two such
// lists and produces a new list representing their sum.

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

void appendSum(Number& numb, int digit) {
    if(numb == NULL) {
        initNode(numb, digit);
    }
    else {
        digitNode* newNode = numb;
        while (newNode->nextNode)
        {
            newNode = newNode->nextNode;
        }
        initNode(newNode->nextNode, digit);
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

int calculateNumOfDigits(Number numb) {
    int digits = 0;
    while (numb)
    {
        digits++;
        numb = numb->nextNode;
    }
    return digits;
}

int sumDigits(int first, int second, Number& sum, int remainder) {
    int digitSum = first + second + remainder;
    if(digitSum >= 10) {
        appendSum(sum, digitSum % 10);
        remainder = 1;
    } else {
        appendSum(sum, digitSum);
        remainder = 0;
    }
    return remainder;
}


Number calculateSum(Number& first, Number& second) {
    int firstLength = calculateNumOfDigits(first);
    int secondLength = calculateNumOfDigits(second);
    if(firstLength < secondLength) {
        Number temp = first;
        first = second;
        second = temp;
    }
    Number sum = NULL;
    int remainder = 0;
    Number firstPointer = first;
    Number secondPointer = second;
    while(secondPointer) {
        remainder = sumDigits(firstPointer->digit, secondPointer->digit, sum, remainder);
        firstPointer = firstPointer->nextNode;
        secondPointer = secondPointer->nextNode;
    }
    
    while (firstPointer)
    {
        remainder = sumDigits(firstPointer->digit, 0, sum, remainder);
        firstPointer = firstPointer->nextNode;
    }
    if(remainder != 0) {
        appendSum(sum, remainder);
    }
    return sum;
}

int main() {
    Number firstNumb = NULL;
    inputNumber(firstNumb);
    cout << "Fist Number is: ";
    printNumber(firstNumb);
    cout << "\n";

    Number secondNumb = NULL;
    inputNumber(secondNumb);
    cout << "Second Number is: ";
    printNumber(secondNumb);
    cout << "\n";
    
    Number sum = NULL;
    sum = calculateSum(firstNumb, secondNumb);
    cout << "Sum is: ";
    printNumber(sum);
    cout << "\n";
    return 0;
}