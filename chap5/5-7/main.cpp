#include <iostream>
using namespace std;

// Take the student record functions from Chapter 4 ( addRecord and averageRecord)
// and use them to create a class representing a collection of student records, as
// before, making sure to implement all necessary constructors, a destructor,
// and an overloaded assignment operator.


class Student {
    private:
        struct studentRecord {
            int id;
            int grade;
            studentRecord* next;
        };
    public:
        Student();
        ~Student();
        Student& operator=(const Student& rhs);
        void addRecord(int ID, int grade);
        double averageRecord();
        void toString();
    private:
        typedef studentRecord* headRecord;
        headRecord _head;
        void deleteRecords(headRecord& head);
        headRecord deepCopy(const headRecord orig);
};

int main() {

    return 0;
}