#include <iostream>
using namespace std;
// P R O B L E M : T R A C K I N G A N U N K N O WN
// Q U A N T I T Y O F S TU D E N T R E C O R D S
// In this problem, you will write a class with methods to store and manipulate a collection
// of student records. A student record contains a student number and a grade, both inte-
// gers, and a string for the student name. The following functions are to be implemented:
// addRecord This method takes a student number, name, and grade and adds a
// new record with this data to the collection.
// recordWithNumber This function takes a student number and retrieves the record
// with that student number from the collection.
// removeRecord This function takes a student number and removes the record with
// that student number from the collection.
// The collection can be of any size. The addRecord operation is expected to be
// called frequently, so it must be implemented efficiently.
class StudentRecord {
    public:
        StudentRecord();
        StudentRecord(int newGrade, int newID, string newName);
        int grade();
        void setGrade(int newGrade);
        int studentID();
        void setStudentID(int newID);
        string name();
        void setName(string newName);
        string letterGrade();
        void printRecord();
    private:
        int _grade;
        int _studentID;
        string _name;
        bool isValidGrade(int grade);
};

StudentRecord::StudentRecord() {
    setGrade(-1);
    setStudentID(-1);
    setName("");
}

StudentRecord::StudentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

int StudentRecord::grade() {
    return _grade;
}

void StudentRecord::setGrade(int newGrade) {
   if (isValidGrade(_grade)) {
        _grade = newGrade;
   }
}

int StudentRecord::studentID() {
    return _studentID;
}

void StudentRecord::setStudentID(int newStudentID) {
    _studentID = newStudentID;
}

string StudentRecord::name() {
    return _name;
}

void StudentRecord::setName(string newName) {
    _name = newName;
}

string StudentRecord::letterGrade() {
    if(!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
}

bool StudentRecord::isValidGrade(int grade) {
    return ((grade >= 0) && (grade <= 100));
}

void StudentRecord::printRecord() {
    cout << "Student's name: " << _name << ", Student's ID: " << _studentID <<
    ", Student's Grade: " << grade() << ", " << letterGrade() << "\n";
}

class StudentCollection {
    private:
        struct studentNode
        {
            StudentRecord studentData;
            studentNode* next;
        };
    public:
        StudentCollection();
        ~StudentCollection();
        StudentCollection(const StudentCollection &original);
        void addRecord(StudentRecord newStudent);
        StudentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        void displayCollection();
        StudentCollection& operator=(const StudentCollection & rhs);
    private:
        typedef studentNode* studentList;
        studentList _listHead;
        bool isLastListItem();
        void deleteList(studentList& listPtr);
        studentList copiedList(const studentList original);
};

void StudentCollection::deleteList(studentList& listPtr)  {
    while (listPtr != NULL) 
    {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

StudentCollection::StudentCollection(const StudentCollection &original) {
    _listHead = copiedList(original._listHead);
}


StudentCollection::~StudentCollection() {
    deleteList(_listHead);
}

StudentCollection::StudentCollection() {
    _listHead = NULL;
}

void StudentCollection::addRecord(StudentRecord newStudent) {
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

StudentRecord StudentCollection::recordWithNumber(int idNum) {
    studentNode* listIterator = _listHead;
    StudentRecord foundRecord;
    while (listIterator != NULL)
    {
        if(listIterator->studentData.studentID() == idNum) {
            foundRecord = listIterator->studentData;
            break;
        }
        listIterator = listIterator->next;
    }
    return foundRecord;
}

void StudentCollection::removeRecord(int idNum) {
    // if(isLastListItem()) {
    //     delete _listHead;
    //     _listHead = NULL;
    //     return;
    // }

    // studentNode* prevRecord = _listHead;
    // studentNode* currRecord = _listHead;
    // while (currRecord != NULL)
    // {
    //     if(currRecord->studentData.studentID() == idNum) {
    //         prevRecord->next = currRecord->next;
    //         delete currRecord;
    //         currRecord = NULL;
    //         currRecord = prevRecord->next;
    //         break;
    //     }
    //     prevRecord = currRecord;
    //     currRecord = currRecord->next;
    // }
    studentNode * loopPtr = _listHead;
    studentNode * trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) return;
    if (trailing == NULL) {
        _listHead = _listHead->next;
    } else {
        trailing->next = loopPtr->next; 
    }
    delete loopPtr;
}

void StudentCollection::displayCollection() {
    studentNode* listIterator = _listHead;
    while (listIterator != NULL)
    {
        listIterator->studentData.printRecord();
        listIterator = listIterator->next;
    }
    if(_listHead == NULL) {
        cout << "Collection is Empty!\n";
    }
}

bool StudentCollection::isLastListItem() {
    return _listHead && _listHead->next == NULL;
}

StudentCollection::studentList StudentCollection::copiedList(const studentList original) {
    if (original == NULL) {
        return NULL;
    }
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

StudentCollection& StudentCollection::operator=(const StudentCollection &rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}


int main() {
     StudentCollection collection;
     collection.addRecord(StudentRecord(15, 1001, "Max"));
     collection.addRecord(StudentRecord(50, 1002, "Ivan"));
     collection.addRecord(StudentRecord(65, 1003, "Roman"));
     collection.addRecord(StudentRecord(42, 1004, "Andrew"));
     collection.addRecord(StudentRecord(33, 1005, "Alex"));
     cout << "Whole collection: \n";
     collection.displayCollection();

     cout << "Record with ID 1003: ";
     StudentRecord rec = collection.recordWithNumber(1003);
     rec.printRecord();
     

    cout << "Nonexistent record: ";
    StudentRecord nonExRec = collection.recordWithNumber(999);
    nonExRec.printRecord();

    StudentCollection collection1(collection);

    //collection1 = collection;
    collection.removeRecord(1001);
    collection.removeRecord(1002);
    collection.removeRecord(1003);
    collection.removeRecord(1004);
    collection.removeRecord(1005);
    collection.displayCollection();

    collection1.displayCollection();
    return 0;
}