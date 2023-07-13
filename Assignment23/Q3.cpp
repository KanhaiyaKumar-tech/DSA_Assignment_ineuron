
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printRightViewUtil(Node* root, int level, int& maxLevel) {
    if (root == NULL)
        return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    printRightViewUtil(root->right, level + 1, maxLevel);
    printRightViewUtil(root->left, level + 1, maxLevel);
}

void printRightView(Node* root) {
    int maxLevel = 0;
    printRightViewUtil(root, 1, maxLevel);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->right = createNode(8);

    cout << "Right view of the binary tree: ";
    printRightView(root);

    return 0;
}
