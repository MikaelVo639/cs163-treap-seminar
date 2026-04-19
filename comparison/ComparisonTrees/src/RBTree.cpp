#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<int> rbTree;
    int val;
    
    int n = 0;
    while (std::cin >> val) {
        n++;
        rbTree.insert(val);
    }

    for(int i = 0; i < n; ++i) rbTree.find(i);

    return 0;
}