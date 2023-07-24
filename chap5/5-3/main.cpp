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
        void concatenate(String& str);
        void toString();
        String& operator=(const String& rhs);
    private:
        typedef charNode* stringHead;
        stringHead _head;
        void initNode(charNode*& node, char newChar);
        void deleteString(stringHead& head);
        stringHead deepCopy(const stringHead orig);
};


int main() {
    String str;
    str.append('H');
    str.append('e');
    str.append('l');
    str.append('l');
    str.append('o');
    str.append('!');
    //str.toString();

    //cout << str.characterAt(4);
    String str1;
    str1.append('W');
    str1.append('o');
    str1.append('r');
    str1.append('l');
    str1.append('d');
    // str.concatenate(str1);
    // str.toString();
    str1.toString();
    str.toString();
    str = str1;
    str.toString();
    str1.toString();
    str.append('!');
    str1.append('?');
    str1.toString();
    str.toString();
    return 0;
}

String::String() {
    _head = NULL;
}

String::~String() {
    deleteString(_head);
}

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

void String::concatenate(String& str) {
    charNode* firstIterator = _head;
    while (firstIterator != NULL && firstIterator->next)
    {
        firstIterator = firstIterator->next;
    }
    
    charNode* secondIterator = str._head;
    while (secondIterator)
    {
        append(secondIterator->letter);
        secondIterator = secondIterator->next;
    }
}

void String::deleteString(stringHead& head) {
    while (head)
    {
        charNode* temp = head;
        head = head->next;
        delete temp;
    }
}

String::stringHead String::deepCopy(const stringHead orig) {
    if(orig == NULL) {
        return NULL;
    }

    stringHead newStringList = new charNode;
    newStringList->letter = orig->letter;

    stringHead newListIterator = newStringList;
    stringHead origIterator = orig->next;
    while (origIterator)
    {
        newListIterator->next = new charNode;
        newListIterator = newListIterator->next;
        newListIterator->letter = origIterator->letter;
        origIterator = origIterator->next;
    }
    newListIterator->next = NULL;
    return newStringList;
}

String& String::operator=(const String& rhs) {
    if(_head != rhs._head) {
        deleteString(_head);
        _head = deepCopy(rhs._head);
    }
    return *this;
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