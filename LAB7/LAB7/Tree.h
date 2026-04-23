#pragma once

template <class T>
class Tree {
public:
    class Node {
    public:
        T value;
        Node** children;
        int num_children;
        int capacity;
        Node* parent;

        Node(T val, Node* p) {
            value = val;
            parent = p;
            num_children = 0;
            capacity = 2;
            children = new Node * [capacity];
        }

        ~Node() {
            for (int i = 0; i < num_children; i++) {
                delete children[i];
            }
            delete[] children;
        }
    };

    Node* root;

    Tree() {
        root = nullptr;
    }

    ~Tree() {
        if (root != nullptr) {
            delete root;
        }
    }

    Node* add_node(Node* parent_node, T value) {
        Node* new_node = new Node(value, parent_node);

        if (parent_node == nullptr) {
            if (root != nullptr) {
                delete root;
            }
            root = new_node;
        }
        else {
            if (parent_node->num_children == parent_node->capacity) {
                int new_capacity = parent_node->capacity * 2;
                Node** new_array = new Node * [new_capacity];

                for (int i = 0; i < parent_node->num_children; i++) {
                    new_array[i] = parent_node->children[i];
                }

                delete[] parent_node->children;
                parent_node->children = new_array;
                parent_node->capacity = new_capacity;
            }

            parent_node->children[parent_node->num_children] = new_node;
            parent_node->num_children++;
        }

        return new_node;
    }

    Node* get_node(Node* parent_node) {
        if (parent_node == nullptr) {
            return root;
        }
        return parent_node;
    }

    void delete_node(Node* node_to_delete) {
        if (node_to_delete == nullptr) {
            return;
        }

        if (node_to_delete->parent != nullptr) {
            Node* p = node_to_delete->parent;
            int index_to_remove = -1;

            for (int i = 0; i < p->num_children; i++) {
                if (p->children[i] == node_to_delete) {
                    index_to_remove = i;
                    break;
                }
            }

            if (index_to_remove != -1) {
                for (int i = index_to_remove; i < p->num_children - 1; i++) {
                    p->children[i] = p->children[i + 1];
                }
                p->num_children--;
            }
        }
        else if (node_to_delete == root) {
            root = nullptr;
        }

        delete node_to_delete;
    }

    Node* find(Node* start_node, T param, bool (*cmp)(T, T)) {
        if (start_node == nullptr) {
            return nullptr;
        }

        if (cmp(param, start_node->value) == true) {
            return start_node;
        }

        for (int i = 0; i < start_node->num_children; i++) {
            Node* found_node = find(start_node->children[i], param, cmp);
            if (found_node != nullptr) {
                return found_node;
            }
        }

        return nullptr;
    }

    Node* insert(Node* parent_node, T value, int index) {
        if (parent_node == nullptr) {
            return nullptr;
        }

        if (index < 0 || index > parent_node->num_children) {
            return nullptr;
        }

        if (parent_node->num_children == parent_node->capacity) {
            int new_capacity = parent_node->capacity * 2;
            Node** new_array = new Node * [new_capacity];

            for (int i = 0; i < parent_node->num_children; i++) {
                new_array[i] = parent_node->children[i];
            }

            delete[] parent_node->children;
            parent_node->children = new_array;
            parent_node->capacity = new_capacity;
        }

        for (int i = parent_node->num_children; i > index; i--) {
            parent_node->children[i] = parent_node->children[i - 1];
        }

        Node* new_node = new Node(value, parent_node);
        parent_node->children[index] = new_node;
        parent_node->num_children++;

        return new_node;
    }

    void sort(Node* node, bool (*cmp)(T, T)) {
        if (node == nullptr || node->num_children < 2) {
            return;
        }

        for (int i = 0; i < node->num_children - 1; i++) {
            for (int j = 0; j < node->num_children - 1 - i; j++) {
                bool cond = false;

                if (cmp != nullptr) {
                    cond = cmp(node->children[j + 1]->value, node->children[j]->value);
                }
                else {
                    cond = node->children[j + 1]->value < node->children[j]->value;
                }

                if (cond == true) {
                    Node* aux = node->children[j];
                    node->children[j] = node->children[j + 1];
                    node->children[j + 1] = aux;
                }
            }
        }
    }

    int count(Node* node) {
        if (node == nullptr) {
            node = root;
        }

        if (node == nullptr) {
            return 0;
        }

        int total_nodes = node->num_children;

        for (int i = 0; i < node->num_children; i++) {
            total_nodes = total_nodes + count(node->children[i]);
        }

        return total_nodes;
    }
};