#include <iostream>
#include <unordered_map>
#include <map>

// For the problem in 7-3, implement a solution using a class from the C++ library.

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


int main() {
    unordered_map<int , StudentData> studentsTable;

    studentsTable.insert({10, StudentData(10, 50, "Max1")});
    studentsTable.insert({2, StudentData(2, 51, "Max2")});
    studentsTable.insert({7, StudentData(7, 98, "Max3")});
    studentsTable.insert({12, StudentData(12, 77, "Max4")});
    studentsTable.insert({1, StudentData(1, 81, "Max5")});
    studentsTable.insert({3, StudentData(3, 21, "Max6")});
    studentsTable.insert({22, StudentData(22, 61, "Max7")});
    studentsTable.insert({33, StudentData(33, 44, "Max8")});
    studentsTable.insert({11, StudentData(11, 11, "Max9")});

    // for(auto it: studentsTable)  {
    //     cout << it.first << " ";
    //     it.second.toString();
    // }

    studentsTable[12].toString();
    return 0;
}