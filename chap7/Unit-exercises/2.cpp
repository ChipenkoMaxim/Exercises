#include <iostream>
#include <cstring>
using namespace std;

// P R O B L E M : E F F IC I E N T T R A V E R S A L
// A programming project will use your studentCollection class. The client code needs the
// ability to traverse all of the students in the collection. Obviously, to maintain information
// hiding, the client code cannot be given direct access to the list, but it’s a requirement
// that the traversals are efficient.

class StudentData;
class Student;
class scIterator;


class StudentData {
    private:
        int _id;
        int _grade;
        string _name;
    public:
        StudentData();
        StudentData(int id, int grade, string name);
        int id();
        void setId(int id);
        int grade();
        void setGrade(int grade);
        string name();
        void setName(string name);
        void toString();
};

StudentData::StudentData() {
    setId(0);
    setGrade(0);
}
StudentData::StudentData(int id, int grade, string name) {
    setId(id);
    setGrade(grade);
    setName(name);
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

string StudentData::name() {
    return _name;
}

void StudentData::setName(string name) {
    _name = name;
}

void StudentData::toString() {
    cout << "Name = " << name() << ", ID = " << id() << ", Grade = " << grade() << "\n";
}

typedef bool (*firstStudentPolicy)(StudentData r1, StudentData r2);

class Student {
    private:
        struct studentRecord {
            StudentData data;
            studentRecord* next;
        };
    public:
        friend class scIterator;
        Student();
        Student(const Student& stud);
        ~Student();
        Student& operator=(const Student& rhs);
        void addRecord(StudentData data);
        double averageRecord();
        Student& recordsWithinRange(int lowerLimit, int upperLimit);
        void toString();
        void setFirstStudentPolicy(firstStudentPolicy f);
        StudentData firstStudent();
        scIterator firstItemIterator();
    private:
        firstStudentPolicy _currentPolicy;
        typedef studentRecord* headRecord;
        headRecord _head;
        void deleteRecords(headRecord& head);
        headRecord deepCopy(const headRecord orig);
        void initRecord(studentRecord*& stud, StudentData data);
};



bool higherGrade(StudentData r1, StudentData r2) {
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(StudentData r1, StudentData r2) {
    return r1.id() < r2.id();
}

bool nameComesFirst(StudentData r1, StudentData r2) {
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}


int main() {
    Student stud;
    // for(int i = 0; i < 100; i++) stud.addRecord(StudentData(1001 + i, 1 + i, "Aboba"));
    stud.addRecord(StudentData(1001, 50, "Max"));
    stud.addRecord(StudentData(1002, 60, "Roman"));
    stud.addRecord(StudentData(1003, 65, "Andrew"));
    stud.addRecord(StudentData(1004, 70, "Larisa"));
    stud.addRecord(StudentData(1005, 60, "Elena"));
    stud.toString();
    StudentData newData;
    stud.setFirstStudentPolicy(nameComesFirst);
    cout << "First Student is: ";
    newData = stud.firstStudent();
    newData.toString();
    cout << "Average record = " << stud.averageRecord() << "\n";
    // Student stud1;
    // stud1 = stud.recordsWithinRange(1, 10);
    // stud1.toString();
    return 0;
}


class scIterator {
    public:
        scIterator();
        scIterator(Student::studentRecord* initial);
        void advance();
        bool pastEnd();
        StudentData student();
    private:
        Student::studentRecord* current;
};


scIterator::scIterator() {
    current = NULL;
}
scIterator::scIterator(Student::studentRecord* initial) {
    current = initial;
}

void scIterator::advance() {
    if(current != NULL) {
        current = current->next;
    }
}

bool scIterator::pastEnd() {
    return current == NULL;
}

StudentData scIterator::student() {
    if(current == NULL) {
        StudentData dummyStud(-1, -1, "");
        return dummyStud;
    } else {
        return current->data;
    }
}



Student::Student() {
    _head = NULL;
    _currentPolicy = NULL;
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
    newStudList->data.setName(orig->data.name());
    headRecord newIter = newStudList;
    headRecord oldIter = orig->next;
    while (oldIter)
    {
        newIter->next = new studentRecord;
        newIter = newIter->next;
        newIter->data.setGrade(oldIter->data.grade());
        newIter->data.setId(oldIter->data.id());
        newIter->data.setName(oldIter->data.name());
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


scIterator Student::firstItemIterator() {
    return scIterator(_head);
}


double Student::averageRecord() {
    scIterator iter;
    int gradeSum = 0;
    int recordNum = 0;
    iter = firstItemIterator();
    while (!iter.pastEnd())
    {
        recordNum++;
        gradeSum += iter.student().grade();
        iter.advance();
    }
    return gradeSum / recordNum;
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
        cout << "Name = " << iter->data.name() << ", ID = " << iter->data.id() << ", Grade = " << iter->data.grade() << "\n";
        iter = iter->next;
    }
}

void Student::setFirstStudentPolicy(firstStudentPolicy f) {
    _currentPolicy = f;
}

StudentData Student::firstStudent() {
    if(_head == NULL || _currentPolicy == NULL) {
        StudentData dummyStud(-1, -1 ,"");
        return dummyStud;
    }
    studentRecord *iter = _head;
    StudentData firstStudent = iter->data;
    iter = iter->next;
    while (iter)
    {
        if(_currentPolicy(iter->data, firstStudent)) {
            firstStudent = iter->data;
        }
        iter = iter->next;
    }
    return firstStudent;
}