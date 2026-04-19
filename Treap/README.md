# Treap Project Implementation Guide

This project implements a **Treap**, which is a randomized binary search tree data structure. It maintains a dynamic set of ordered keys while naturally avoiding the unbalanced $O(N)$ depth issues of standard BSTs.

## 1. Project Structure

The source code is organized into three files for modularity and maintainability:

- **`function.h`**: Contains the `Node` structure definition and function prototypes.
- **`function.cpp`**: Implements the core logic (Split, Merge, Insert, Erase, Union).
- **`main.cpp`**: Provides an interactive command-line interface (CLI) for testing.

## 2. Technical Features

- **mt19937 (Mersenne Twister)**: A high-quality random number generator used to ensure the tree height remains proportional to $O(log(N))$.
- **BST Property**: For any given node, all nodes in its left subtree have smaller keys, and all nodes in its right subtree have larger keys.
- **Heap Property**: Every parent node has a higher priority than its children.
- **Cross-Platform UI**: Includes a `clearScreen()` function compatible with both Windows (`cls`) and Unix/Linux/macOS (`clear`).
- **Input Validation**: Prevents the program from crashing when a user enters non-numeric data.

## 3. Core Algorithms

- **Split**: Divides a treap into two separate sub-treaps (left and right) based on a target key.
- **Merge**: Merge two distinct treaps into one tree, assuming all keys in the first are smaller than those in the second.
- **Insert**: Generates a random priority and uses `split` and `merge` to place the new key.
- **Erase**: Isolates a specific key through splits and merges the remaining branches.
- **Union**: A divide-and-conquer function to combine two treaps with overlapping keys.

## 4. Compilation & Execution

To compile this project manually using the **g++** compiler, follow these steps in your terminal:

### Step 1: Compile the logic

```bash
g++ -c function.cpp -std=c++11
```

### Step 2: Compile the main interface

```bash
g++ -c main.cpp -std=c++11
```

### Step 3: Link the object files

```bash
g++ main.o function.o -o treap_app
```

### Step 4: Run the program

- **Windows**: `./treap_app.exe`
- **Linux/macOS**: `./treap_app`

## 5. Usage Instructions

1. After running the program, use the menu to interact with the Treap.
2. The screen clears after each operation to keep the interface clean.
3. If the Treap is empty, the "Show All" option will notify you accordingly.
