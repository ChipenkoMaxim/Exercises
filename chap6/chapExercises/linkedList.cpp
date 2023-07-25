#include <iostream>

using namespace std;

// Write a recursive function that is given a singly linked list where the data type is integer.
// The function returns the count of negative numbers in the list.

struct List {
    int data;
    List* next = NULL;
};
typedef List* listHead;

void addToList(listHead& list, int newData) {
    List* iter = list;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = new List;
    iter->next->data = newData;
    iter->next->next = NULL;
}


void printList(listHead list) {
    if(list == NULL) return;
    cout << list->data << "\n";
    printList(list->next);
}

int calcNegatives(listHead list) {
    if(list == NULL) return 0;
    int count = calcNegatives(list->next);
    if(list->data < 0) count++;
    return count;
}


int main() {
    listHead list = new List;
    list->data = -1;
    addToList(list, 1);
    addToList(list, -1);
    addToList(list, 1);
    addToList(list, -1);
    addToList(list, 1);
    addToList(list, -1);
    addToList(list, 1);
    addToList(list, -1);
    addToList(list, 1);
    addToList(list, 1);
    printList(list);
    cout << "Number of negatives integers in list = " << calcNegatives(list) << "\n";
    return 0;
}