#include <iostream>

// Write a function removeRecord that takes a pointer to a studentCollection and a
// student number and that removes the record with that student number from
// the collection.



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
        // student* newStudent = findPlaceInList(studentList->nextStudent);
        // initRecord(newStudent->nextStudent, ID, grade);
        student* newStudent = NULL;
        initRecord(newStudent, ID, grade);
        newStudent->nextStudent = studentList;
        studentList = newStudent;
    }
}

int calcNumOfRecords(student* list) {
    int numb = 0;
    for(;list;numb++) {
        list = list->nextStudent;
    }
    return numb;
}

int calcSumOfGrades(student* list) {
    int sum = 0;
    while (list)
    {
        sum+= list->grade;
        list = list->nextStudent;
    }
    return sum;
}

double averageRecord(student* list) {
    int numOfRecords = calcNumOfRecords(list);
    int sumOfGrades = calcSumOfGrades(list);
    cout << "sum = " << sumOfGrades << "\n";
    return sumOfGrades / numOfRecords;
}

void printStudentsList(student* studentList) {
    while (studentList != NULL)
    {
        cout << studentList->ID << " " << studentList->grade << "\n";
        studentList = studentList->nextStudent;
    }
}


void removeRecord(student*& list, int index) {
    if(index == 1 && list->nextStudent == NULL) {
        delete list;
        list = NULL;
    }
    else if(index == 1 && list->nextStudent) {
        student* stud = list->nextStudent;
        delete list;
        list = stud;
    } else {
        student* prevStud = list;
        student* currStud = list->nextStudent;
        for(int i = 2; i < index; i++)
        {
            prevStud = currStud;
            currStud = currStud->nextStudent;
        }
        prevStud->nextStudent = currStud->nextStudent;
        delete currStud;
    }
}


int main() {
    student* students = NULL;
    for(int i = 0; i < 7; i++) {
        addRecord(students, 1000 + i, (2 + i) * (i + 1));
    }
    printStudentsList(students);
    for(int i = 0; i < 7; i++) removeRecord(students, 7 - i);
    cout << "AFTER:\n";
    printStudentsList(students);
    // double average = averageRecord(students);
    // cout << "Average = " << average << "\n";
    return 0;
}