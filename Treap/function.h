#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <random>
#include <string>

struct Treap {
    struct Node {
        int key;
        unsigned int prio;
        Node *left, *right;

        Node(int k, unsigned int p);
    };

    Node* root;
    static std::mt19937 rng;

    Treap();
    ~Treap();

    // Core algorithms
    void split(Node* t, int k, Node*& l, Node*& r);
    Node* merge(Node* l, Node* r);
    void insert(int k);
    void erase(int k);
    Node* unionTreaps(Node* l, Node* r);

    // Utilities
    bool find(int k);
    void printInOrder(Node* t);
    void clear(Node* t);
};

// UI Helper Functions
void displayMenu();
void clearScreen();
void pause();

#endif
