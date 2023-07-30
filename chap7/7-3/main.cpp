#include <iostream>
using namespace std;

// Consider a collection of studentRecord objects. We want to be able to quickly
// find a particular record based on student number. Store the student records
// in an array, sort the array by student number, and investigate and implement
// the interpolation search algorithm.


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

void insertionSort(StudentData arr[], int size) {
    int start = 0;
    int end = size - 1;
    for(int i = start + 1; i <= end; i++) {
        for (int j = i; j > start && arr[j - 1].id() > arr[j].id(); j--)
        {
            StudentData temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}

StudentData interpolationSearch(StudentData arr[], int size, int elem) {
    StudentData foundElem(-1, -1, "");
    int left = 0;
    int right = size - 1;
    while (left <= right && arr[left].id() <= elem && elem <= arr[right].id())
    {
        int pos = left + (elem - arr[left].id()) * (right - left) / (arr[right].id() - arr[left].id());
        if(arr[pos].id() == elem) {
            foundElem = arr[pos];
            break;
        } else if(elem < arr[pos].id()) right = pos - 1;
        else left = pos + 1;
    }
    return foundElem;
}



const int  STUDENT_ARRAY_SIZE = 10;

int main() {
   StudentData studArr[STUDENT_ARRAY_SIZE];
   studArr[0] = StudentData(1010, 95, "Max1");
   studArr[1] = StudentData(1009, 75, "Max2");
   studArr[2] = StudentData(1008, 20, "Max3");
   studArr[3] = StudentData(1007, 35, "Max4");
   studArr[4] = StudentData(1006, 42, "Max5");
   studArr[5] = StudentData(1005, 33, "Max6");
   studArr[6] = StudentData(1004, 15, "Max7");
   studArr[7] = StudentData(1003, 35, "Max8");
   studArr[8] = StudentData(1002, 15, "Max9");
   studArr[9] = StudentData(1001, 35, "Max10");
   for(int i = 0; i < STUDENT_ARRAY_SIZE; i++) studArr[i].toString();
   
   insertionSort(studArr, STUDENT_ARRAY_SIZE);
   cout << "\n\n";
   for(int i = 0; i < STUDENT_ARRAY_SIZE; i++) studArr[i].toString();

   StudentData stud = interpolationSearch(studArr, STUDENT_ARRAY_SIZE, 1005);
   cout << "Founded Elem is: ";
   stud.toString();
   return 0;
}