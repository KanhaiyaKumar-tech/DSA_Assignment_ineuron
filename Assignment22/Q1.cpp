#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convertToDLL(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    static TreeNode* prev = nullptr; // Global variable to keep track of previously visited node

    TreeNode* head = convertToDLL(root->left);

    if (prev == nullptr) {
        head = root; // First node in in-order traversal
    } else {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    convertToDLL(root->right);

    return head;
}

void printDLL(TreeNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->right != nullptr) {
            std::cout << " <-> ";
        } else {
            std::cout << " <-> nullptr";
        }
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);

    TreeNode* head = convertToDLL(root);

    std::cout << "Output: ";
    printDLL(head);

    return 0;
}


