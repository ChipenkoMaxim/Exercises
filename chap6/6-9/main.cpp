#include <iostream>
// Some words in programming have more than one common meaning. In
// Chapter 4, we learned about the heap, from which we get memory allocated
// with new. The term heap also describes a binary tree in which each node value
// is higher than any in the left or right subtree. Write a recursive function to
// determine whether a binary tree is a heap.
using namespace std;

struct tree {
    int data;
    tree* left = NULL;
    tree* right = NULL;
};
typedef tree* treeRoot;

void traverseTree(treeRoot node) {
    if(node == NULL) return;
    traverseTree(node->left);
    cout << node->data << " ";
    traverseTree(node->right);
}

bool isHeapTree(treeRoot node) {
    if(node == NULL) return 1;
    if(node->left == NULL && node->right == NULL) return 1;
    int leftSubtree = isHeapTree(node->left);
    int rightSubTree = isHeapTree(node->right);
    bool res;
    if(node->left == NULL && node->right != NULL) {
        res =  node->data > node->right->data && leftSubtree && rightSubTree;
    } else if(node->left != NULL && node->right == NULL) {
        res =  node->data > node->left->data && leftSubtree && rightSubTree;
    } else {
        res = node->data > node->left->data && node->data > node->right->data && leftSubtree && rightSubTree;
    }
    return res;
}


int main() {
    treeRoot root = new tree;
    root->data = 10;
    root->left = new tree;
    root->left->data = 9;
    root->left->left = new tree;
    root->left->left->data = 7;
    root->left->right = new tree;
    root->left->right->data = 6;

    root->right = new tree;
    root->right->data = 8;
    root->right->left = new tree;
    root->right->left->data = 5;
    root->right->right = new tree;
    root->right->right->data = 4;
    traverseTree(root);
    cout << "\n" << isHeapTree(root) << "\n";
    return 0;
}