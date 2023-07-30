#include <iostream>
#include <cstring>
using namespace std;

// P R O B L E M : S O R T I N G S O M E , L E A V IN G O T H E R S A L O N E
// A project requires you to sort an array of studentRecord objects by grade, but
// there’s a catch. Another part of the program is using a special grade value of –1
// to indicate a student whose record cannot be moved. So while all the other records
// must be moved around, those with –1 grades should be left exactly where they are,
// resulting in an array that is sorted except for –1 grades interspersed throughout.

class StudentData;


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


const int  STUDENT_ARRAY_SIZE = 10;

void insertionSort(StudentData arr[], int size) {
    int start = 0;
    int end = size - 1;
    for(int i = start + 1; i <= end; i++) {
        for(int j = i; j > start && arr[j - 1].grade() > arr[j].grade(); j--) {
            StudentData temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}


int main() {
   StudentData studArr[STUDENT_ARRAY_SIZE];
   studArr[0] = StudentData(1001, 95, "Max1");
   studArr[1] = StudentData(1002, 75, "Max2");
   studArr[2] = StudentData(1003, 85, "Max3");
   studArr[3] = StudentData(1004, 65, "Max4");
   studArr[4] = StudentData(1005, 55, "Max5");
   studArr[5] = StudentData(1006, 15, "Max6");
   studArr[6] = StudentData(1007, 15, "Max7");
   studArr[7] = StudentData(1008, 35, "Max8");
   studArr[8] = StudentData(1009, 55, "Max9");
   studArr[9] = StudentData(1010, 35, "Max10");
   insertionSort(studArr, STUDENT_ARRAY_SIZE);
   for(int i = 0; i < STUDENT_ARRAY_SIZE; i++) studArr[i].toString();
   return 0;
}