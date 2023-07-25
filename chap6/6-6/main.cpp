#include <iostream>
//Solve exercise 6-2 again, using a linked list instead of an array.


using namespace std;

struct List {
    bool data;
    List* next = NULL;
};
typedef List* listHead;


void fillNode(List*& node) {
    if(node == NULL) {
        node = new List;
    }
    node->data = (rand() % 2);
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


bool hasOddParityIterative(listHead list) {
    int numOfOnes = 0;
    while(list) {
        if(list->data == 1) numOfOnes++;
        list = list->next;
    }
    return numOfOnes % 2;
}

bool hasOddParityRecursive(listHead list) {
    if(list == NULL) return 0;
    int current = list->data;
    int restArrResult = hasOddParityRecursive(list->next);
    return current ^ restArrResult;
}


int main() {
    srand(time(NULL));
    listHead head = new List;
    fillList(head, 10);
    printList(head);
    cout << hasOddParityIterative(head) << "\n";
    cout << hasOddParityRecursive(head) << "\n";
    return 0;
}