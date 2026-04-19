#include "function.h"
#include <limits>

int main() {
    Treap myTreap;
    bool running = true;

    while (running) {
        clearScreen(); // Always start with a fresh screen
        displayMenu();

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << ">> Error: Invalid input type!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            pause();
            continue;
        }

        if (choice == 1) {
            int val;
            std::cout << "Value to insert: "; std::cin >> val;
            myTreap.insert(val);
            std::cout << ">> Key added successfully." << std::endl;
            pause();
        }
        else if (choice == 2) {
            int val;
            std::cout << "Value to erase: "; std::cin >> val;
            myTreap.erase(val);
            std::cout << ">> Erase operation done." << std::endl;
            pause();
        }
        else if (choice == 3) {
            int val;
            std::cout << "Value to find: "; std::cin >> val;
            if (myTreap.find(val)) std::cout << ">> RESULT: Found!" << std::endl;
            else std::cout << ">> RESULT: Not Found." << std::endl;
            pause();
        }
        else if (choice == 4) {
            if (myTreap.root == nullptr) {
                std::cout << ">> Treap is currently empty." << std::endl;
            } else {
                std::cout << ">> Treap Elements (Sorted): ";
                myTreap.printInOrder(myTreap.root);
                std::cout << std::endl;
            }
            pause();
        }
        else if (choice == 5) {
            std::cout << "Shutting down..." << std::endl;
            running = false;
        }
        else {
            std::cout << ">> Please enter a number between 1 and 5." << std::endl;
            pause();
        }
    }

    return 0;
}
