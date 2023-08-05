#include <iostream>

// Suppose you are working on a project in which a particular studentRecord
// may need to be augmented with one of the following pieces of data: term
// paper title, year of enrollment, or a bool indicating whether the student is
// auditing the class. You don’t want to include all of these data fields in the
// base studentRecord class, knowing that in most cases they won’t be used. Your
// first thought is to create three subclasses, each having one of the data fields,
// with names such as studentRecordTitle, studentRecordYear and studentRecordAudit.
// Then you are informed that some student records will contain two of these
// additional data fields or perhaps all three. Creating subclasses for each
// possible variation is impractical. Find a design pattern that addresses this
// conundrum, and implement a solution.


using namespace std;

class DescribeStudentInterface {
    public:
        virtual void toString() = 0;
};

class StudentData : public DescribeStudentInterface {
    private:
        int _id;
        int _grade;
        string _name;
    public:
        StudentData();
        StudentData(int id, int grade, string name);
        void toString();
};

StudentData::StudentData() {
    _id = -1;
    _grade = -1;
    _name = "";
}
StudentData::StudentData(int id, int grade, string name) {
    _id = id;
    _grade = grade;
    _name = name;
}

void StudentData::toString() {
    cout << "Name = " << _name << ", ID = " << _id << ", Grade = " << _grade;
}



class DescribeStudentDecorator : public DescribeStudentInterface {
    private:
        DescribeStudentInterface* interface;
    public:
        DescribeStudentDecorator();
        DescribeStudentDecorator(DescribeStudentInterface* newInterface);
        void toString();
};

DescribeStudentDecorator::DescribeStudentDecorator() {}

DescribeStudentDecorator::DescribeStudentDecorator(DescribeStudentInterface* newInterface) {
    interface = newInterface;
}

void DescribeStudentDecorator::toString() {
    interface->toString();
}


class TermPaperTitleData : public DescribeStudentDecorator{
    private:
        string _termPaperTitle;
    public:
        TermPaperTitleData(string termPaperTitle, DescribeStudentInterface* inter);
        void toString();
};


TermPaperTitleData::TermPaperTitleData(string termPaperTitle, DescribeStudentInterface* inter) : DescribeStudentDecorator(inter) {
    _termPaperTitle = termPaperTitle;
}

void TermPaperTitleData::toString() {
    DescribeStudentDecorator::toString();
    cout << ", TermPaperTitleData = " << _termPaperTitle;
}


class YearOfEnrolmentData : public DescribeStudentDecorator {
    private:
        int _yearOfEnrolment;
    public:
        YearOfEnrolmentData(int yearOfEnrolment, DescribeStudentInterface* newInter);
        void toString();
};

YearOfEnrolmentData::YearOfEnrolmentData(int yearOfEnrolment, DescribeStudentInterface* newInter) : DescribeStudentDecorator(newInter) {
    _yearOfEnrolment = yearOfEnrolment;
}

void YearOfEnrolmentData::toString() {
    DescribeStudentDecorator::toString();
    cout << ", Year of Enrolment = " << _yearOfEnrolment;
}

class AuditData : public DescribeStudentDecorator {
    private:
        bool _isStudentAuditClass;
    public:
        AuditData(bool isStudentAudit, DescribeStudentInterface* newInter);
        void toString();
};

AuditData::AuditData(bool isStudentAudit, DescribeStudentInterface* newInter) : DescribeStudentDecorator(newInter) {
    _isStudentAuditClass = isStudentAudit;
}

void AuditData::toString() {
    DescribeStudentDecorator::toString();
    cout << ", Is Student Audit the class = " << _isStudentAuditClass ? "Yes" : "No";
}

int main() {
    DescribeStudentInterface* a = new AuditData(1, new YearOfEnrolmentData(2017, new TermPaperTitleData("Password Manager", new StudentData(1001, 100, "Max"))));
    a->toString();
    cout << "\n";
    return 0;
}
