#include <iostream>

using namespace std;
// PROBLEM: CLASS ROSTER
// Design a class or set of classes for use in a program that maintains a class roster. For
// each student, store the student’s name, ID, and final grade score in the range 0–100.
// The program will allow student records to be added or removed; display the record of
// a particular student, identified by ID, with the grade displayed as a number and as a
// letter; and display the average score for the class. The appropriate letter grade for a
// particular score is shown in Table 5-1.


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
    private:
        int _grade;
        int _studentID;
        string _name;
        bool isValidGrade(int grade);
};

StudentRecord::StudentRecord() {
    setGrade(0);
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

int main() {
    StudentRecord test(10, 1001, "Max");
    return 0;
}

