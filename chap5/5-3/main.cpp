#include <iostream>
// Take the variable-length string functions from Chapter 4 (append, concatenate,
// and characterAt) and use them to create a class for variable-length strings,
// making sure to implement all necessary constructors, a destructor, and an
// overloaded assignment operator.


using namespace std;

class String {
    private:
        struct charNode {
            char letter;
            charNode* next;
        };
    public:
        String();
        ~String();
        void append(char newChar);
        char characterAt(int index);
        void concatenate(String str);
        void toString();
    private:
        typedef charNode* stringHead;
        stringHead _head;
        void initNode(charNode*& node, char newChar);
};


int main() {
    String str;
    str.append('H');
    str.append('e');
    str.append('l');
    str.append('l');
    str.append('o');
    str.append('!');
    str.toString();

    cout << str.characterAt(4);
    return 0;
}

String::String() {
    _head = NULL;
}

String::~String() {}

void String::initNode(charNode*& node, char newChar) {
    node = new charNode;
    node->letter = newChar;
    node->next = NULL;
}


void String::append(char newChar) {
    if(_head == NULL) {
        initNode(_head, newChar);
        return;
    }

    charNode* iterator = _head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    initNode(iterator->next, newChar);
}

char String::characterAt(int index) {
    charNode* str = _head;
    while (str && index)
    {
        str = str->next;
        index--;
    }
    if(str == NULL) return '\0';
    return str->letter;
}

void String::toString() {
    charNode* iterator = _head;
    while (iterator != NULL)
    {
        cout << iterator->letter;
        iterator = iterator->next;
    }
    cout << "\n";
}