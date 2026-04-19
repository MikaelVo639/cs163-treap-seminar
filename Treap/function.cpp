#include "function.h"
#include <cstdlib>

std::mt19937 Treap::rng(std::random_device{}());

Treap::Node::Node(int k, unsigned int p) : key(k), prio(p), left(nullptr), right(nullptr) {}

Treap::Treap() : root(nullptr) {}

void Treap::split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    if (t->key <= k) {
        split(t->right, k, t->right, r);
        l = t;
    } else {
        split(t->left, k, l, t->left);
        r = t;
    }
}

Treap::Node* Treap::merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->prio > r->prio) {
        l->right = merge(l->right, r);
        return l;
    } else {
        r->left = merge(l, r->left);
        return r;
    }
}

void Treap::insert(int k) {
    if (find(k)) return;
    Node *L, *R;
    split(root, k, L, R);
    Node* newNode = new Node(k, rng());
    root = merge(merge(L, newNode), R);
}

void Treap::erase(int k) {
    Node *L, *M, *R;
    split(root, k - 1, L, R);
    split(R, k, M, R);
    if (M) delete M;
    root = merge(L, R);
}

Treap::Node* Treap::unionTreaps(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->prio < r->prio) std::swap(l, r);
    Node *lt, *rt;
    split(r, l->key, lt, rt);
    l->left = unionTreaps(l->left, lt);
    l->right = unionTreaps(l->right, rt);
    return l;
}

bool Treap::find(int k) {
    Node* curr = root;
    while (curr) {
        if (curr->key == k) return true;
        curr = (k < curr->key) ? curr->left : curr->right;
    }
    return false;
}

void Treap::printInOrder(Node* t) {
    if (!t) return;
    printInOrder(t->left);
    std::cout << t->key << " ";
    printInOrder(t->right);
}

void Treap::clear(Node* t) {
    if (!t) return;
    clear(t->left);
    clear(t->right);
    delete t;
}

Treap::~Treap() { clear(root); }

void displayMenu() {
    std::cout << "\n========== TREAP CONTROL PANEL ==========" << std::endl;
    std::cout << "1. Insert a Key" << std::endl;
    std::cout << "2. Erase a Key" << std::endl;
    std::cout << "3. Find a Key" << std::endl;
    std::cout << "4. Show All Elements" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Enter choice: ";
}

void clearScreen() {
    // Cross-platform clear screen
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
