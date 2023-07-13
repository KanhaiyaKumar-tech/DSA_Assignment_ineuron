#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* flipBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root;
    }

    TreeNode* newRoot = flipBinaryTree(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;

    return newRoot;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Input Tree: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode* flippedRoot = flipBinaryTree(root);

    std::cout << "Output Tree: ";
    printTree(flippedRoot);
    std::cout << std::endl;

    return 0;
}

