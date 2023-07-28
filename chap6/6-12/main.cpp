#include <iostream>

// Design your own: Consider basic statistical questions you can ask of a set of
// numerical values, such as average, median, mode, and so forth. Attempt to
// write recursive functions to compute those statistics for a binary tree of integers.
// Some are easier to write than others. Why?


using namespace std;

class Tree {
    private:
        struct treeNode
        {
            int data;
            treeNode* left = NULL;
            treeNode* right = NULL;
        };
    public:
        Tree();
        void addNode(int newData);
        void printTree();
        void size();
        double average();
    private:
        typedef treeNode* treeRoot;
        treeRoot _root;
        void privateAddNode(treeRoot& root, int newData);
        void privatePrintTree(treeRoot root);
        int treeSize(treeRoot root);
        int calcSum(treeRoot root);
};

int main() {
    Tree tr;
    tr.addNode(10);
    tr.addNode(2);
    tr.addNode(7);
    tr.addNode(12);
    tr.addNode(1);
    tr.addNode(1);
    tr.addNode(1);
    tr.addNode(2);
    tr.addNode(1);
    tr.addNode(7);
    tr.addNode(7);
    tr.addNode(7);
    tr.printTree();
    tr.size();
    cout << "Average = "  << tr.average() << "\n";
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
    cout << root->data << " ";
    privatePrintTree(root->right);
}

void Tree::addNode(int newData) {
    privateAddNode(_root, newData);
}

void Tree::privateAddNode(treeRoot& root, int newData) {
    if(root == NULL) {
        root = new treeNode;
        root->data = newData;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(newData >= root->data) privateAddNode(root->right, newData);
    else if(newData <= root->data) privateAddNode(root->left, newData);
}

int Tree::treeSize(treeRoot root) {
    if(root == NULL) return 0;

    int leftSize = treeSize(root->left);
    int rightSize = treeSize(root->right);
    int currVertex = 1;

    return leftSize + rightSize + currVertex;
}

void Tree::size() {
    int size = treeSize(_root);
    cout << size << "\n";
}

double Tree::average() {
    return (double)calcSum(_root) / (double)treeSize(_root);
}

int Tree::calcSum(treeRoot root) {
    if(root == NULL) return 0;
    int leftSum = calcSum(root->left);
    int rightSum = calcSum(root->right);

    return leftSum + rightSum + root->data;
}