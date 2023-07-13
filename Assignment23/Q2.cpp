
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

void printLeftViewUtil(Node* root, int level, int& maxLevel) {
    if (root == NULL)
        return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    printLeftViewUtil(root->left, level + 1, maxLevel);
    printLeftViewUtil(root->right, level + 1, maxLevel);
}

void printLeftView(Node* root) {
    int maxLevel = 0;
    printLeftViewUtil(root, 1, maxLevel);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(5);
    root->right = createNode(2);
    root->right->left = createNode(3);
    root->right->right = createNode(1);
    root->right->left->left = createNode(6);
    root->right->left->right = createNode(7);

    cout << "Left view of the binary tree: ";
    printLeftView(root);

    return 0;
}
