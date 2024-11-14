#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findIndex(const vector<int>& arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(const vector<int>& inorder, const vector<int>& preorder, int& pi, int iStart, int iEnd) {
    if (iStart > iEnd) return nullptr;

    int rootVal = preorder[pi];
    pi++;

    Node* root = new Node(rootVal);

    if (iStart == iEnd) return root;

    int rootIndex = findIndex(inorder, rootVal);

    root->left = buildTree(inorder, preorder, pi, iStart, rootIndex - 1);
    root->right = buildTree(inorder, preorder, pi, rootIndex + 1, iEnd);

    return root;
}

void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    int currentLevel = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        cout <<currentLevel + 1 << ":";

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->data;
            if (i < levelSize - 1) cout << ",";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout <<endl;
        currentLevel++;
    }
}

int main() {
    string preStr, inStr;
    getline(cin, preStr);
    getline(cin, inStr);

    stringstream preStream(preStr);
    stringstream inStream(inStr);

    vector<int> preorder, inorder;
    int num;

    while (preStream >> num) {
        preorder.push_back(num);
    }

    while (inStream >> num) {
        inorder.push_back(num);
    }

    int pi = 0;
    Node* root = buildTree(inorder, preorder, pi, 0, inorder.size() - 1);

    levelOrderTraversal(root);
    delete root;

    return 0;
}
