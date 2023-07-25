#include <iostream>
// Solve exercise 6-1 again, using a linked list instead of an array.

using namespace std;

struct List {
    int data;
    List* next = NULL;
};
typedef List* listHead;


void fillNode(List*& node) {
    if(node == NULL) {
        node = new List;
    }
    node->data = (rand() % 10) + 1;
    if(rand() % 2) node->data *= -1;
    node->next = NULL;
}

void fillList(listHead& list, int N) {
    fillNode(list);
    List* iter = list;
    for(int i = 0; i < N; i++) {
        fillNode(iter->next);
        iter = iter->next;
        iter->next = NULL;
    }
}

void printList(listHead list) {
    if(list == NULL) {
        cout << "\n";
        return;
    }
    cout << list->data << " ";
    printList(list->next);
}


int calcSumOfPositiveIter(listHead list) {
    int sum = 0;
    while (list)
    {
        if(list->data > 0) sum += list->data;
        list = list->next;
    }
    return sum;
}

int calcSumOfPositiveRecur(listHead list) {
    if(list == NULL) return 0;
    int sum = calcSumOfPositiveRecur(list->next);
    if(list->data > 0) sum += list->data;
    return sum;
}



int main() {
    srand(time(NULL));
    listHead head = new List;
    fillList(head, 10);
    printList(head);
    cout <<  calcSumOfPositiveIter(head) << "\n";
    cout << calcSumOfPositiveRecur(head) << "\n";
    return 0;
}