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

void preorder(Node* root, bool &first) {
    if (root == nullptr) return;
    if (!first) cout << " ";
    cout << root->val;
    first = false;
    preorder(root->left, first);
    preorder(root->right, first);
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

    int k;
    cin >> k;

    Node* target = find(root, k);
    bool first = true;
    preorder(target, first);
    cout << endl;

    return 0;
}