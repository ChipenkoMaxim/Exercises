#include <iostream>

using namespace std;


struct student {
    int grade;
    int studentID;
    string name;
};

void printArray(student* arr, const int arrSize) {
    cout << "\n";
    for(int i = 0; i < arrSize; i++) {
        cout << "Grade = " << arr[i].grade << ", ID = " << arr[i].studentID << ", Name = " << arr[i].name << endl;
    }
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

    printArray(studentArray, ARRAY_SIZE);

    return 0;
}