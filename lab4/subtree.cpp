#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int v) {
    if (root == nullptr) return new Node(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

Node* find(Node* root, int x) {
    while (root != nullptr && root->val != x) {
        if (x < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}

int subtreeSize(Node* root) {
    if (root == nullptr) return 0;
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        root = insert(root, a);
    }

    int x;
    cin >> x;

    Node* target = find(root, x);
    cout << subtreeSize(target) << endl;

    freeTree(root);
    return 0;
}