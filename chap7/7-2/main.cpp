#include <iostream>
#include <list>
#include <algorithm>

// Rewrite our studentCollection functions from Chapter 4 (addRecord and
// averageRecord) so that instead of directly implementing a linked list, you
// use a class from the C++ library.

using namespace std;

struct student
{
    int ID = 0;
    int grade = 0;
};

void addRecord(list<student> &studList, int ID, int grade) {
    student newStud;
    newStud.ID = ID;
    newStud.grade = grade;
    studList.push_front(newStud);
}

double averageRecord(list<student> studList) {
    int sum = 0;
    for(student stud: studList) {
        sum += stud.grade;
    }
    return (double)sum / studList.size();
}

void printStudentsList(list<student> studentList) {
    for(student stud: studentList) {
        cout << "ID = " << stud.ID << ", Grade = " << stud.grade << "\n";
    }
}


int main() {
    list<student> students;
    addRecord(students, 1001, 50);
    addRecord(students, 1002, 20);
    addRecord(students, 1003, 12);
    addRecord(students, 1004, 86);
    addRecord(students, 1005, 76);
    addRecord(students, 1006, 51);
    addRecord(students, 1007, 52);
    addRecord(students, 1008, 53);
    addRecord(students, 1009, 54);
    addRecord(students, 1010, 55); 
    printStudentsList(students);
    cout << "Average Record Grade = " << averageRecord(students) << "\n";
    return 0;
}