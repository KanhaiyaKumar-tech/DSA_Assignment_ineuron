
#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    int hd;
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

void printBottomView(Node* root) {
    if (root == NULL)
        return;

    map<int, int> hdMap;
    queue<Node*> q;

    root->hd = 0;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int hd = temp->hd;
        int data = temp->data;

        hdMap[hd] = data;

        if (temp->left != NULL) {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }

    for (auto it = hdMap.begin(); it != hdMap.end(); ++it) {
        cout << it->second << " ";
    }
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(5);
    root->left->right = createNode(3);
    root->right->right = createNode(25);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);

    cout << "Bottom view of the binary tree: ";
    printBottomView(root);

    return 0;
}
