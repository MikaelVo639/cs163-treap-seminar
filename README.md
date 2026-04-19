# CS163: Data Structures - Treap Seminar

This project is a Seminar assignment for the Data Structures course (CS163), focusing on the research, implementation, performance evaluation, and practical applications of the **Treap** data structure.

## Repository Structure

* `presentation/`: Contains presentation materials (PPTX, PDF slides).
* `treap/`: Contains the C++ source code for the Standard Treap implementation.
* `programing_assignment/`: Source code, algorithm analysis files, and test cases (`.inp`/`.out`) for 4 competitive programming problems demonstrating the power of Treaps.
* `comparison/`: Contains source code, datasets and results when comparing treap with other data structures and naive solution.

## Overview of Treap

A Treap is a randomized self-balancing binary search tree (combining the concepts of Tree and Heap).

* **BST (Binary Search Tree) Property:** For any given node, all nodes in its left subtree have smaller keys, and all nodes in its right subtree have larger keys.
* **Heap Property:** Each node is assigned a random priority when created. The structure maintains a Max-Heap property, meaning the priority of a parent node is always greater than or equal to its children.
* Thanks to this randomness, the expected height of a Treap is $O(\log_2(N))$, ensuring optimal performance for query, insertion, and deletion operations without the need for complex tree rotation rules like in AVL or Red-Black Trees.

## Core Operations

A Treap operates mainly on two fundamental operations:

* **Split:** Divides a Treap into two smaller Treaps based on a target key.
* **Merge:** Combines two Treaps into one (with the prerequisite that all keys in the left Treap must be strictly smaller than all keys in the right Treap).
* **Insert** and **Erase** operations both utilize `Split` to isolate elements, followed by a `Merge` of the remaining branches.
* **Implicit Treap:** A powerful variant that removes explicit keys and uses "subtree size" as an implicit index. This transforms the Treap into a high-speed dynamic array structure.

## Programming Assignments

Our group implemented solutions for 4 advanced problems from programming competitions (Codeforces, CSES, IOI) to showcase the practical applications of Treaps:

1. **Game (IOI 2013):** Utilizes a 2D Segment Tree model where each Segment Tree node manages an Implicit Treap (Sparse Structure). This allows for efficient handling of a $10^9 \times 10^9$ grid and 2D GCD queries without exceeding memory limits.
2. **Reversals and Sums (CSES 2074):** Applies Implicit Treap combined with Lazy Propagation techniques to reverse contiguous subarrays and calculate range sums in $O(M \log N)$ time.
3. **Substring Reversals (CSES 2073):** Manages strings similarly to a "Rope" structure using an Implicit Treap, enabling instant cutting and reversing of substrings.
4. **Yaroslav and Points (Codeforces 295E):** The Treap dynamically manages the distances between points on a coordinate system. Each node stores the number of points, the sum of coordinates, and the sum of distances within its subtree to process queries rapidly.
