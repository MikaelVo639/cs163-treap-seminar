#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    int key;
    int priority;
    Node *left, *right;

    Node(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

void split(Node* t, int key, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
    } else if (t->key <= key) {
        split(t->right, key, t->right, r);
        l = t;
    } else {
        split(t->left, key, l, t->left);
        r = t;
    }
}

void merge(Node*& t, Node* l, Node* r) {
    if (!l || !r) {
        t = l ? l : r;
    } else if (l->priority > r->priority) {
        merge(l->right, l->right, r);
        t = l;
    } else {
        merge(r->left, l, r->left);
        t = r;
    }
}

void insert(Node*& root, int key) {
    Node *l, *r;
    split(root, key, l, r);
    Node* newNode = new Node(key);
    merge(l, l, newNode);
    merge(root, l, r);
}

bool find(Node* t, int key) {
    if (!t) return false;
    if (t->key == key) return true;
    return find(key < t->key ? t->left : t->right, key);
}

int main() {
    srand(time(0)); 
    
    Node* root = nullptr;
    int val;

    int n = 0;
    while (std::cin >> val) {
        n++;
        if (!find(root, val)) {
            insert(root, val);
        }
    }

    for(int i = 0; i < n; ++i) if(find(root, i));

    return 0;
}