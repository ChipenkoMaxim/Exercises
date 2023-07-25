#include <iostream>
//Solve exercise 6-3 again, using a linked list instead of an array.


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


int calcTargetOccurrencesIterative(listHead list, int target) {
    int numOfTarget = 0;
    while (list)
    {
        if(list->data == target) numOfTarget++;
        list = list->next;
    }
    return numOfTarget;
}

int calcTargetOccurrencesRecursive(listHead list, int target) {
    if(list == NULL) return 0;
    int quantity = calcTargetOccurrencesRecursive(list->next, target);
    if(list->data == target) quantity++;
    return quantity;
}


int main() {
    srand(time(NULL));
    listHead head = new List;
    fillList(head, 10);
    printList(head);
    cout << "Num of 5s = " << calcTargetOccurrencesIterative(head, 5) << "\n";
    cout << "Num of 5s = " << calcTargetOccurrencesRecursive(head, 5) << "\n";
    return 0;
}