#include <iostream>
#include <string>
using namespace std;

int calculateDepth(string preorder, int& index) {
    if (index >= preorder.length())
        return 0;

    if (preorder[index] == 'l') {
        index++;
        return 1;
    }

    if (preorder[index] == 'n') {
        index++;
        int leftDepth = calculateDepth(preorder, index);
        int rightDepth = calculateDepth(preorder, index);
        return 1 + max(leftDepth, rightDepth);
    }

    return 0;
}

int main() {
    string preorder = "nlnll";
    int index = 0;
    int depth = calculateDepth(preorder, index);
    depth -= 1;
    cout << "Depth of the binary tree: " << depth  << endl;

    return 0;
}
