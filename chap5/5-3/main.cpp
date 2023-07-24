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
};



int main() {
    return 0;
}

String::String() {
    _head = NULL;
}