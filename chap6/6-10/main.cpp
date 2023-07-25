#include <iostream>
// /A binary search tree is a binary tree in which each node value is greater than
// any value in that node’s left subtree but less than any value in the node’s
// right subtree. Write a recursive function to determine whether a binary tree
// is a binary search tree.

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

bool isPrivateBinarySearchTree(treeRoot node, int& currElem) {
    if(node == NULL) return 1;
    int leftSubtree = isPrivateBinarySearchTree(node->left, currElem);

    int res = node->data > currElem;
    currElem = node->data;

    int rightSubTree = isPrivateBinarySearchTree(node->right, currElem);
    return res && leftSubtree && rightSubTree;
}


bool isBinarySearchTree(treeRoot node) {
    int currElem = -1;
    return isPrivateBinarySearchTree(node, currElem);
}

int main() {
    treeRoot root = new tree;
    root->data = 5;
    root->left = new tree;
    root->left->data = 3;
    root->left->left = new tree;
    root->left->left->data = 1;
    root->left->right = new tree;
    root->left->right->data = 4;

    root->right = new tree;
    root->right->data = 8;
    root->right->left = new tree;
    root->right->left->data = 7;
    root->right->right = new tree;
    root->right->right->data = 9;
    traverseTree(root);
    cout << "\n" << isHeapTree(root) << "\n";
    cout << isBinarySearchTree(root) << "\n";
    return 0;
}