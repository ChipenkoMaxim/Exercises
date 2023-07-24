//charNode*& operator[]();

#include <iostream>
// For the variable-length string class of the previous exercise, replace the
// characterAt method with an overloaded [] operator. For example, if myString
// is an object of our class, then myString[1] should return the same result as
// myString.characterAt(1).


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
        void concatenate(String& str);
        void toString();
        String& operator=(const String& rhs);
        char& operator[](int index);
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


    String str1;
    str1.append('W');
    str1.append('o');
    str1.append('r');
    str1.append('l');
    str1.append('d');


    str1.toString();
    str.toString();
    str = str1;
    str.toString();
    str1.toString();
    str.append('!'); 
    str1.append('?');
    str1.toString();
    str.toString();

    str1[5] = str[5];
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

char& String::operator[](int index) {
    charNode* str = _head;
    while (str && index)
    {
        str = str->next;
        index--;
    }
    if(str == NULL) exit(0);
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