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

int running = 0;
bool firstPrinted = true;

void reverseInorder(Node* root) {
    if (root == nullptr) return;
    reverseInorder(root->right);
    running += root->val;
    root->val = running;               // new key of this node
    if (!firstPrinted) cout << " ";
    cout << root->val;
    firstPrinted = false;
    reverseInorder(root->left);
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

    reverseInorder(root);
    cout << endl;
    return 0;
}