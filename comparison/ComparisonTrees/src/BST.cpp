#include <iostream>

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    bool find(Node* node, int key) {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }

public:
    BST() : root(nullptr) {}
    void insert(int key) { root = insert(root, key); }
    bool find(int key) { return find(root, key); }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    BST tree;
    int val;
    
    int n = 0;
    while (std::cin >> val) {
        n++;
        tree.insert(val);
    }

    for(int i = 0; i < n; ++i) if(tree.find(i));

    return 0;
}