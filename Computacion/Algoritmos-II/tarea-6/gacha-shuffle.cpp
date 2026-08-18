#include <bits/stdc++.h>

using namespace std;

mt19937 rnd (time(NULL));

class BST {
private:
    struct BSTNode {
        string data;
        BSTNode* left;
        BSTNode* right;

        BSTNode(string val) : data(val), left(nullptr), right(nullptr) {}
    };

    BSTNode* root;

    BSTNode* insertHelper(BSTNode* node, string val) {
        if (node == nullptr) {
            return new BSTNode(val);
        }

        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else {
            node->right = insertHelper(node->right, val);
        }

        return node;
    }

    BSTNode* searchHelper(BSTNode* node, string val) {
        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->data) {
            return searchHelper(node->left, val);
        } else if (val > node->data) {
            return searchHelper(node->right, val);
        } else {
            return node;
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(string val) {
        root = insertHelper(root, val);
    }

    BSTNode* search(string val) {
        return searchHelper(root, val);
    }
};

int main() {
    int n; cin >> n;

    string s;
    BST bst;
    int cnt = 0;

    vector<string> v (n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    shuffle(begin(v), end(v), rnd);

    for (string s : v) {
        if (!bst.search(s)) {
            bst.insert(s);
            cnt++;
        }
    }

    cout << cnt;
}