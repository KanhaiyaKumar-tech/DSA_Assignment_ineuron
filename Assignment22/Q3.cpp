#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printRootToLeafPaths(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<TreeNode*> nodes;
    std::stack<std::vector<int>> paths;

    nodes.push(root);
    paths.push(std::vector<int>());

    while (!nodes.empty()) {
        TreeNode* current = nodes.top();
        nodes.pop();

        std::vector<int> currentPath = paths.top();
        paths.pop();

        currentPath.push_back(current->val);

        if (current->left == nullptr && current->right == nullptr) {
            // Leaf node, print the path
            std::cout << "Path: ";
            for (int i = 0; i < currentPath.size(); i++) {
                std::cout << currentPath[i];
                if (i < currentPath.size() - 1) {
                    std::cout << "->";
                }
            }
            std::cout << std::endl;
        }

        if (current->right != nullptr) {
            nodes.push(current->right);
            paths.push(currentPath);
        }

        if (current->left != nullptr) {
            nodes.push(current->left);
            paths.push(currentPath);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    std::cout << "Root-to-Leaf Paths:" << std::endl;
    printRootToLeafPaths(root);

    return 0;
}
