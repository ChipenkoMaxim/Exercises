#include <iostream>
// Design your own: Try to discover a linked-list processing problem that is
// difficult to solve using iteration but can be solved directly using recursion.
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



int findMin(listHead list) {
    int min = list->data;
    list = list->next;
    while(list) {
        if(list->data < min) min = list->data;
        list = list->next;
    }
    return min;
}

int findMinRecur(listHead list) {
    if(list->next == NULL) return list->data;
    int min = findMin(list->next);
    if(list->data < min) min = list->data;
    return min;
}

int main() {
    srand(time(NULL));
    listHead head = new List;
    fillList(head, 10);
    printList(head);
    cout << "Min = " << findMin(head) << "\n";
    cout << "Min = " << findMinRecur(head) << "\n";
    return 0;
}