#include <iostream>
#include <vector>

bool areTraversalsSame(std::vector<int>& inorder, std::vector<int>& preorder, std::vector<int>& postorder) {
    if (inorder.empty() && preorder.empty() && postorder.empty()) {
        return true;
    }

    if (inorder.size() != preorder.size() || inorder.size() != postorder.size()) {
        return false;
    }

    if (preorder[0] != postorder[postorder.size() - 1]) {
        return false;
    }

    int rootIndex = -1;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[0]) {
            rootIndex = i;
            break;
        }
    }

    if (rootIndex == -1) {
        return false;
    }

    std::vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    std::vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

    std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
    std::vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());

    std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
    std::vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end() - 1);

    bool leftSame = areTraversalsSame(leftInorder, leftPreorder, leftPostorder);
    bool rightSame = areTraversalsSame(rightInorder, rightPreorder, rightPostorder);

    return leftSame && rightSame;
}

int main() {
    std::vector<int> inorder = {4, 2, 5, 1, 3};
    std::vector<int> preorder = {1, 2, 4, 5, 3};
    std::vector<int> postorder = {4, 5, 2, 3, 1};

    if (areTraversalsSame(inorder, preorder, postorder)) {
        std::cout << "Yes, the traversals are of the same tree." << std::endl;
    } else {
        std::cout << "No, the traversals are not of the same tree." << std::endl;
    }

    return 0;
}
