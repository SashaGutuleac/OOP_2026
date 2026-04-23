#include <iostream>
#include "Literals.h"
#include "Tree.h"
using namespace std;
bool compare_equals(int param, int node_val) {
    if (param == node_val) {
        return true;
    }
    else {
        return false;
    }
}

bool sort_descending(int a, int b) {
    if (a > b) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << a << "\n";
    cout << b << "\n";

    Tree<int> tree;

    Tree<int>::Node* root = tree.add_node(nullptr, 10);
    Tree<int>::Node* child1 = tree.add_node(root, 5);
    Tree<int>::Node* child2 = tree.add_node(root, 20);

    tree.insert(root, 15, 1);

    cout << tree.count(nullptr) << "\n";

    Tree<int>::Node* found = tree.find(root, 15, compare_equals);
    if (found != nullptr) {
         cout << "Gasit 15\n";
    }

    tree.sort(root, sort_descending);
    cout << root->children[0]->value << "\n";

    tree.delete_node(child2);
    cout << tree.count(nullptr) << "\n";

    return 0;
}