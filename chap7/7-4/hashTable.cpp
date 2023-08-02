#include <iostream>

// For the problem in 7-3, implement a solution by implementing an abstract
// data type that allows an arbitrary number of items to be stored and individual
// records to be retrieved based on a key value. A generic term for a structure
// that can efficiently store and retrieve items based on a key value is a symbol
// table, and common implementations of the symbol table idea are hash tables
// and binary search trees.

using namespace std;
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


class StudentsTable {
    public:
        StudentsTable();
        void insert(StudentData student);
        StudentData search(int studentID);
    private:
        void fillTable();
        int hashFunction(int studentID);
        int tableSize = 21;
        StudentData table[21];
};


StudentsTable::StudentsTable() { fillTable();}


void StudentsTable::fillTable() {
    for(int i = 0; i < tableSize; i++) table[i] = StudentData();
}

int StudentsTable::hashFunction(int studentID) {
    return studentID % tableSize;
}

void StudentsTable::insert(StudentData student) {
    int index = hashFunction(student.id());
    while (table[index].id() != 0) 
    {
        index = (index + 1) % tableSize;
    }
    table[index] = student;
}

StudentData StudentsTable::search(int studentID) {
    int index = hashFunction(studentID);
    while (table[index].id() != studentID && table[index].id() != 0)
    {
        index = (index + 1) % tableSize;
    }
    if(table[index].id() != studentID) {
        return StudentData(-1, -1, "");
    }
    return table[index];
}


int main() {
    StudentsTable table;
    table.insert(StudentData(10, 50, "Max1"));
    table.insert(StudentData(2, 51, "Max2"));
    table.insert(StudentData(7, 98, "Max3"));
    table.insert(StudentData(12, 77, "Max4"));
    table.insert(StudentData(1, 81, "Max5"));
    table.insert(StudentData(3, 21, "Max6"));
    table.insert(StudentData(22, 61, "Max7"));
    table.insert(StudentData(33, 44, "Max8"));
    table.insert(StudentData(11, 11, "Max9"));

    cout << "Found student is ";
    table.search(22).toString();

    return 0;
}