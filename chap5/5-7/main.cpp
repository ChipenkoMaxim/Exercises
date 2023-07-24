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
        Student(const Student& stud);
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
        void initRecord(studentRecord*& stud, int id, int grade);
        int calcNumOfRecords();
        int calcSumOfGrades();
};

int main() {
    Student stud;
    for(int i = 0; i < 100; i++) stud.addRecord(1001 + i, i + 1);
    stud.toString();
    cout << "Average record = " << stud.averageRecord();
    return 0;
}

Student::Student() {
    _head = NULL;
}

Student::Student(const Student& stud) {
    _head = deepCopy(stud._head);
}

Student::~Student() {
    deleteRecords(_head);
}

void Student::deleteRecords(headRecord& head) {
    while (head)
    {
        studentRecord* temp = head;
        head = head->next;
        delete temp;
    }
}

Student& Student::operator=(const Student& rhs) {
    if(_head != rhs._head) {
        deleteRecords(_head);
        _head = deepCopy(rhs._head);
    }
    return *this;
}

Student::headRecord Student::deepCopy(const headRecord orig) {
    if(orig == NULL) return NULL;

    headRecord newStudList = new studentRecord;
    newStudList->grade = orig->grade;
    newStudList->id = orig->id;
    headRecord newIter = newStudList;
    headRecord oldIter = orig->next;
    while (oldIter)
    {
        newIter->next = new studentRecord;
        newIter = newIter->next;
        newIter->grade = oldIter->grade;
        newIter->id = oldIter->id;
        oldIter = oldIter->next;
    }
    newIter->next = NULL;
    return newStudList;
}

void Student::initRecord(studentRecord*& stud, int id, int grade) {
    stud = new studentRecord;
    stud->grade = grade;
    stud->id = id;
    stud->next = NULL;
}

void Student::addRecord(int ID, int grade) {
    if(_head == NULL) {
        initRecord(_head, ID, grade);
        return;
    }

    studentRecord* iterator = _head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    initRecord(iterator->next, ID, grade);
}

int Student::calcNumOfRecords() {
    studentRecord* iter = _head;
    int num = 0;
    while (iter)
    {
        num++;
        iter = iter->next;
    }
    return num;
}

int Student::calcSumOfGrades() {
    studentRecord* iter = _head;
    int sum = 0;
    while (iter)
    {
        sum += iter->grade;
        iter = iter->next;
    }
    return sum;
}


double Student::averageRecord() {
    return calcSumOfGrades() / calcNumOfRecords();
}

void Student::toString() {
    studentRecord* iter = _head;
    while (iter)
    {
        cout << "ID = " << iter->id << ", Grade = " << iter->grade << "\n";
        iter = iter->next;
    }
}