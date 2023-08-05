#include <iostream>
#include <unordered_map>
#include <map>


// Develop a solution to the problem described in 7-6 that does not make use
// of the pattern you discovered but instead solves the problem using C++
// library classes. Rather than focusing on the three particular data fields
// described in the previous question, try to make a general solution: a version
// of the studentRecord class that allows arbitrary extra fields of data to be added
// to particular objects. So, for example, if sr1 is a studentRecord , you might want
// client code to make the call sr1.addExtraField("Title", "Problems of Unconditional
// Branching"), and then later sr1.retrieveField("Title") would return “Problems
// of Unconditional Branching.”


using namespace std;
class StudentData;


class StudentData {
    private:
        unordered_map<string, string> studentPropertyTable;
    public:
        StudentData();
        void addExtraField(string key, string value);
        string retrieveField(string key);
        void toString();
};

StudentData::StudentData() {}

void StudentData::addExtraField(string key, string value) {
    studentPropertyTable.insert({key, value});
}

string StudentData::retrieveField(string key) {
    return studentPropertyTable[key];
}

void StudentData::toString() {
    for(auto iter:studentPropertyTable) {
        cout << iter.first << " = " << iter.second << "\n";
    }
}


int main() {
    StudentData a;
    a.addExtraField("ID", "1001");
    a.addExtraField("Grade", "100");
    a.addExtraField("Name", "Maxim");
    a.addExtraField("YearOfEnrollment", "2017");
    a.addExtraField("IsAuditClass", "No");
    a.addExtraField("TermPaperTitle", "Password Manager");
    a.toString();

    cout << a.retrieveField("ID");
    return 0;
}