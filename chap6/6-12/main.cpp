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
        int median();
        int mode();
    private:
        typedef treeNode* treeRoot;
        treeRoot _root;
        void privateAddNode(treeRoot& root, int newData);
        void privatePrintTree(treeRoot root);
        int treeSize(treeRoot root);
        int calcSum(treeRoot root);
        void findMedian(treeRoot root, int& offsetFromStart, int& median);
        void findMode(treeRoot root, int& frequency, int& maxFrequency, int& mode, int& maxMode);
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
    tr.addNode(10);
    tr.addNode(10);
    tr.addNode(10);
    tr.addNode(10);
    tr.addNode(10);

    tr.printTree();
    tr.size();
    cout << "Average = "  << tr.average() << "\n";
    cout << "Median = " << tr.median() << "\n";
    cout << "Mode = " << tr.mode() << "\n";
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

int Tree::median() {
    int medianSubs = treeSize(_root) / 2;
    int median = -1;
    findMedian(_root, medianSubs, median);
    return median;
}

void Tree::findMedian(treeRoot root, int& offsetFromStart, int& median) {
    if(root == NULL) return;

    findMedian(root->left, offsetFromStart, median);
    offsetFromStart--;
    if(offsetFromStart == 0) median = root->data;
    findMedian(root->right, offsetFromStart, median);
}


int Tree::mode() {
    int frequency = 0;
    int maxFrequency = 0;
    int mode = -1;
    int maxMode = -1;
    findMode(_root, frequency, maxFrequency ,mode, maxMode);
    return maxMode;
}


void Tree::findMode(treeRoot root, int& frequency , int& maxFrequency,int& mode, int& maxMode) {
    if(root == NULL) return;
    
    findMode(root->left, frequency, maxFrequency, mode, maxMode);
    if(mode == -1) {
        mode = root->data;
        frequency++;
        maxFrequency = frequency;
        maxMode = mode;
    } else if(mode == root->data) {
        frequency++;
    } else if(mode != root->data && frequency > maxFrequency) {
        maxFrequency = frequency;
        frequency = 0;
        maxMode = mode;
        mode = root->data;
    } else {
        mode = root->data;
        frequency = 0;
    }
    findMode(root->right, frequency, maxFrequency, mode, maxMode);
}