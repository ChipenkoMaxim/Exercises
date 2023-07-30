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


class Tree {
    private:
        struct treeNode
        {
            StudentData data;
            treeNode* left = NULL;
            treeNode* right = NULL;
        };
    public:
        Tree();
        void addNode(StudentData newData);
        void printTree();
        StudentData studentById(int id);
    private:
        typedef treeNode* treeRoot;
        treeRoot _root;
        void privateAddNode(treeRoot& root, StudentData newData);
        void privatePrintTree(treeRoot root);
        StudentData studentByIdPrivate(treeRoot root, int id);
};

int main() {
    Tree tr;
    tr.addNode(StudentData(10, 50, "Max1"));
    tr.addNode(StudentData(2, 51, "Max2"));
    tr.addNode(StudentData(7, 98, "Max3"));
    tr.addNode(StudentData(12, 77, "Max4"));
    tr.addNode(StudentData(1, 81, "Max5"));
    tr.addNode(StudentData(3, 21, "Max6"));
    tr.addNode(StudentData(22, 61, "Max7"));
    tr.addNode(StudentData(33, 44, "Max8"));
    tr.addNode(StudentData(11, 11, "Max9"));
    tr.printTree();
    StudentData stud = tr.studentById(0);
    cout << "Found student is: ";
    stud.toString();
    return 0;
}

Tree::Tree() {
    _root = NULL;
}

void Tree::printTree() {
    privatePrintTree(_root);
    cout << "\n";
}

void Tree::privatePrintTree(treeRoot root) {
    if(root == NULL) return;
    privatePrintTree(root->left);
    cout << "ID = " << root->data.id() << ", Name = " << root->data.name() << ", Grade = " << root->data.grade() << "\n";
    privatePrintTree(root->right);
}

void Tree::addNode(StudentData newData) {
    privateAddNode(_root, newData);
}

void Tree::privateAddNode(treeRoot& root, StudentData newData) {
    if(root == NULL) {
        root = new treeNode;
        root->data = newData;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(newData.id() >= root->data.id()) privateAddNode(root->right, newData);
    else if(newData.id() <= root->data.id()) privateAddNode(root->left, newData);
}

StudentData Tree::studentByIdPrivate(treeRoot root, int id) {
    if(root == NULL) return StudentData(-1, -1, "");
    if(root->data.id() == id) return root->data;
    if(id < root->data.id()) return studentByIdPrivate(root->left, id);
    if(id > root->data.id()) return studentByIdPrivate(root->right, id);
    return StudentData(-1, -1, "");
}


StudentData Tree::studentById(int id) {
    return studentByIdPrivate(_root, id);
}

