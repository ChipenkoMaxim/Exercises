#include <iostream>
#include <string>
using namespace std;


typedef struct{
    int grade;
    int studentID;
    char name[20];
} student;

void printArray(student* arr, const int arrSize) {
    cout << "\n";
    for(int i = 0; i < arrSize; i++) {
        cout << "Grade = " << arr[i].grade << " " << arr[i].studentID << endl;
    }
}

int gradeComparator(const void* first, const void* second) {
    // student* A = (student*)(fist);
    // student* B = (student*)(second);
    int A = ((student*)first)->grade;
    int B = ((student*)second)->grade;
    return A - B;
}

// int idComparator(const void* fist, const void* second) {
//     student* A = (student*)(fist);
//     student* B = (student*)(second);

//     return A->studentID - B->studentID;
// }


int main() {
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 1,"s"},
        {28, 2, "s"},
        {100, 3, "s"},
        {78, 4, "s"},
        {84, 5, "s"},
        {98, 6, "s"},
        {75, 7, "s"},
        {70, 8, "s"},
        {81, 9, "s"},
        {68, 10, "s"}
    };

    printArray(studentArray, ARRAY_SIZE);
    qsort(studentArray, ARRAY_SIZE, sizeof(student), gradeComparator);
    
    printArray(studentArray, ARRAY_SIZE);
    return 0;
}