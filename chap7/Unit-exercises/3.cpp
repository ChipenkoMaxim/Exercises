#include <iostream>
#include <cstring>
#include <algorithm>
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
        if(arr[i].grade() != -1) {
            int rightSwap = i;
            for(int leftSwap = i - 1; leftSwap >= start && (arr[leftSwap].grade() > arr[rightSwap].grade() 
            || arr[leftSwap].grade() == -1); leftSwap--) {
                if(arr[leftSwap].grade() != -1) {
                    StudentData temp = arr[leftSwap];
                    arr[leftSwap] = arr[rightSwap];
                    arr[rightSwap] = temp;
                    rightSwap = leftSwap;
                }
            }
        }
    }
}

// int compareStudentData(const void* voidA, const void* voidB) {
//     // //StudentData* A = (StudentData*)voidA;
//     StudentData* A;
//     A = (StudentData*)voidA;
//     // //StudentData* B = (StudentData*)voidB;
//     StudentData* B;
//     B = (StudentData*)voidB;
//     B->grade();
//     return A->grade() - B->grade();
// }


void sortByQuickSort(StudentData arr[], int size) {
    StudentData sortedStud[size];
    int sortedCount = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i].grade() != -1) {
            sortedStud[sortedCount] = arr[i];
            sortedCount++;
        }
    }
    insertionSort(sortedStud, sortedCount);
    //qsort(sortedStud, sortedCount, sizeof(StudentData), compareStudentData);
    for(int i = 0, j = 0; i < size; i++) {
        if(arr[i].grade() != -1) {
            arr[i] = sortedStud[j];
            j++;
        }
    }
}


int main() {
   StudentData studArr[STUDENT_ARRAY_SIZE];
   studArr[0] = StudentData(1001, 95, "Max1");
   studArr[1] = StudentData(1002, 75, "Max2");
   studArr[2] = StudentData(1003, -1, "Max3");
   studArr[3] = StudentData(1004, -1, "Max4");
   studArr[4] = StudentData(1005, -1, "Max5");
   studArr[5] = StudentData(1006, -1, "Max6");
   studArr[6] = StudentData(1007, 15, "Max7");
   studArr[7] = StudentData(1008, 35, "Max8");
   studArr[8] = StudentData(1009, -1, "Max9");
   studArr[9] = StudentData(1010, 35, "Max10");
   for(int i = 0; i < STUDENT_ARRAY_SIZE; i++) studArr[i].toString();
   cout << "\n\n";
   sortByQuickSort(studArr, STUDENT_ARRAY_SIZE);
   for(int i = 0; i < STUDENT_ARRAY_SIZE; i++) studArr[i].toString();
   return 0;
}