#include <iostream>

using namespace std;

// Are you disappointed we didn’t do more with sorting? I’m here to help. To
// make sure you are comfortable with qsort, write code that uses the function
// to sort an array of our student struct. First have it sort by grade, and then try
// it again using the student ID.



typedef struct{
    int grade;
    int studentID;
    char name[20];
} student;

void printArray(student* arr, const int arrSize) {
    cout << "\n";
    for(int i = 0; i < arrSize; i++) {
        cout << "Grade = " << arr[i].grade << ", ID = " << arr[i].studentID << ", Name = " << arr[i].name << endl;
    }
    cout << "\n";
}

int gradeComparator(const void* fist, const void* second) {
    student* A = (student*)(fist);
    student* B = (student*)(second);

    return (A->grade - B->grade);
}

int idComparator(const void* fist, const void* second) {
    student* A = (student*)(fist);
    student* B = (student*)(second);

    return A->studentID - B->studentID;
}


int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    cout << "Unsorted array:";
    printArray(studentArray, ARRAY_SIZE);

    cout << "Sorted by grade:";
    qsort(studentArray, ARRAY_SIZE, sizeof(student), gradeComparator);
    printArray(studentArray, ARRAY_SIZE);

    cout << "Sorted by ID: ";
    qsort(studentArray, ARRAY_SIZE, sizeof(student), idComparator);
    printArray(studentArray, ARRAY_SIZE);
    return 0;
}