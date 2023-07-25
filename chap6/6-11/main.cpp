#include <iostream>

// Write a recursive function that is passed a binary search tree’s root pointer and
// a new value to be inserted and that creates a new node with the new value,
// placing it in the correct location to maintain the binary search tree structure.
// Hint: Consider making the root pointer parameter a reference parameter.


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
    private:
        typedef treeNode* treeRoot;
        treeRoot _root;
        void privateAddNode(treeRoot& root, int newData);
        void privatePrintTree(treeRoot root);
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
    tr.printTree();
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