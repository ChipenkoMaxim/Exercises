#include <iostream>
using namespace std;

// For the student record collection class of the previous exercise, add a method
// RecordsWithinRange that takes a low grade and a high grade as parameters and
// returns a new collection consisting of the records in that range (the original
// collection is unaffected). For example, myCollection.RecordsWithinRange(75, 80)
// would return a collection of all records with grades in the range 75–80 inclusive.

// typedef bool (*firstStudentPolicy)(studentRecord r1, studentRecord r2);


class StudentData {
    private:
        int _id;
        int _grade;
    public:
        StudentData();
        StudentData(int id, int grade);
        int id();
        void setId(int id);
        int grade();
        void setGrade(int grade);
};

StudentData::StudentData() {
    setId(0);
    setGrade(0);
}
StudentData::StudentData(int id, int grade) {
    setId(id);
    setGrade(grade);
}

int StudentData::id() {
    return _id;
}

void StudentData::setId(int id) {
    _id = id;
}

int StudentData::grade() {
    return _grade;
}

void StudentData::setGrade(int grade) {
    _grade = grade;
}


class Student {
    private:
        struct studentRecord {
            StudentData data;
            studentRecord* next;
        };
    public:
        Student();
        Student(const Student& stud);
        ~Student();
        Student& operator=(const Student& rhs);
        //void addRecord(int ID, int grade);
        void addRecord(StudentData data);
        double averageRecord();
        Student& recordsWithinRange(int lowerLimit, int upperLimit);
        void toString();
    private:
        typedef studentRecord* headRecord;
        headRecord _head;
        void deleteRecords(headRecord& head);
        headRecord deepCopy(const headRecord orig);
        void initRecord(studentRecord*& stud, StudentData data);
        int calcNumOfRecords();
        int calcSumOfGrades();
};

int main() {
    Student stud;
    for(int i = 0; i < 100; i++) stud.addRecord(StudentData(1001 + i, 1 + i));
    stud.toString();
    cout << "Average record = " << stud.averageRecord() << "\n";
    Student stud1;
    stud1 = stud.recordsWithinRange(1, 10);
    stud1.toString();
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
    newStudList->data.setGrade(orig->data.grade());
    newStudList->data.setId(orig->data.id());
    headRecord newIter = newStudList;
    headRecord oldIter = orig->next;
    while (oldIter)
    {
        newIter->next = new studentRecord;
        newIter = newIter->next;
        newIter->data.setGrade(oldIter->data.grade());
        newIter->data.setId(oldIter->data.id());
        oldIter = oldIter->next;
    }
    newIter->next = NULL;
    return newStudList;
}

void Student::initRecord(studentRecord*& stud, StudentData data) {
    stud = new studentRecord;
    stud->data = data;
    stud->next = NULL;
}

void Student::addRecord(StudentData data) {
    if(_head == NULL) {
        initRecord(_head, data);
        return;
    }

    studentRecord* iterator = _head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    initRecord(iterator->next, data);
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
        sum += iter->data.grade();
        iter = iter->next;
    }
    return sum;
}


double Student::averageRecord() {
    return calcSumOfGrades() / calcNumOfRecords();
}

Student& Student::recordsWithinRange(int lowerLimit, int upperLimit) {
    Student* newList = new Student;
    if((lowerLimit > 100 || lowerLimit < 1) || (upperLimit > 100 || upperLimit < 1)) return *newList;
    studentRecord* iter = _head;
    while (iter)
    {
        if((iter->data.grade() <= upperLimit) && (iter->data.grade() >= lowerLimit)) {
            newList->addRecord(iter->data);
        }
        iter = iter->next;
    }
    return *newList;
}

void Student::toString() {
    studentRecord* iter = _head;
    while (iter)
    {
        cout << "ID = " << iter->data.id() << ", Grade = " << iter->data.grade() << "\n";
        iter = iter->next;
    }
}