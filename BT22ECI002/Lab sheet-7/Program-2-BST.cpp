#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    Node* findMinimumNode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    int getMinimum() {
        Node* minimumNode = findMinimumNode(root);
        if (minimumNode != nullptr) {
            return minimumNode->data;
        }
        return -1; // Indicate that the tree is empty
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);

    int minimum = bst.getMinimum();
    if (minimum != -1) {
        cout << "Minimum element: " << minimum << endl;
    } else {
        cout << "The tree is empty." << endl;
    }

    return 0;
}
