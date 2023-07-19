// P R O B L E M : T R A C K I N G A N U N K N O WN
// Q U A N T I T Y O F S TU D E N T R E C O R D S
// In this problem, you will write functions to store and manipulate a collection of student
// records. A student record contains a student number and a grade, both integers. The
// following functions are to be implemented:
// addRecord
//  This function takes a pointer to a collection of student records (a student
// number and a grade), and it adds a new record with this data to the collection.
// averageRecord This function takes a pointer to a collection of student records
// and returns the simple average of student grades in the collection as a double.
// The collection can be of any size. The addRecord operation is expected to be
// called frequently, so it must be implemented efficiently.

#include <iostream>

using namespace std;

struct student
{
    int ID = 0;
    int grade = 0;
    student* nextStudent = NULL;
};

void initRecord(student*& record, int ID, int grade) {
    record = new student;
    record->ID = ID;
    record->grade = grade;
}

student* findPlaceInList(student* list) {
    while (list->nextStudent)
    {
        list = list->nextStudent;
    }
    return list;
}


void addRecord(student*& studentList, int ID, int grade) {
    if(studentList == NULL) {
        initRecord(studentList, ID, grade);
    } else if(studentList->nextStudent == NULL) {
        initRecord(studentList->nextStudent, ID, grade);
    } else {
        student* newStudent = findPlaceInList(studentList->nextStudent);
        initRecord(newStudent->nextStudent, ID, grade);
    }
}

void printStudentsList(student* studentList) {
    while (studentList != NULL)
    {
        cout << studentList->ID << " " << studentList->grade << "\n";
        studentList = studentList->nextStudent;
    }
}

int main() {
    student* students = NULL;
    for(int i = 0; i < 15; i++) {
        addRecord(students, 1000 + i, 50 + i);
    }
    printStudentsList(students);
    return 0;
}