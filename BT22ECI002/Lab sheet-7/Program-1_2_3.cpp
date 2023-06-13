#include <iostream>
#include <climits>
#define endl "\n"
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Stack {
private:
    class StackNode {
        public: 
        Node* data;
        StackNode* next;

        StackNode(Node* value, StackNode* nextNode = nullptr) {
            data = value;
            next = nextNode;
        }
    };

    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(Node* value) {
        StackNode* newNode = new StackNode(value, top);
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }

        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    Node* getTop() {
        if (isEmpty()) {
            return nullptr;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Custom Queue ADT
class Queue {
private:
    class QueueNode {
        public:
        Node* data;
        QueueNode* next;

        QueueNode(Node* value, QueueNode* nextNode = nullptr) {
            data = value;
            next = nextNode;
        }
    };

    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(Node* value) {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    Node* getFront() {
        if (isEmpty()) {
            return nullptr;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Function to find the inorder successor of a given node
Node* findInorderSuccessor(Node* root, Node* node) {
    if (node->right) {
        // If the node has a right child, find the leftmost node in its right subtree
        Node* current = node->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    } else {
        // If the node doesn't have a right child, use stack for inorder traversal
        Stack stack;
        Node* current = root;
        bool found = false;

        while (!stack.isEmpty() || current != nullptr) {
            if (current != nullptr) {
                stack.push(current);
                current = current->left;
            } else {
                current = stack.getTop();
                stack.pop();

                if (found) {
                    return current;
                }

                if (current == node) {
                    found = true;
                }

                current = current->right;
            }
        }
    }

    return nullptr;
}

// Recursive function to compute the height of a binary tree
int computeHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = computeHeight(root->left);
    int rightHeight = computeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Recursive function to compute the number of nodes having only right child
int computeNumRightChildOnly(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftCount = computeNumRightChildOnly(root->left);
    int rightCount = computeNumRightChildOnly(root->right);

    if (root->left == nullptr && root->right != nullptr) {
        return leftCount + rightCount + 1;
    } else {
        return leftCount + rightCount;
    }
}

// Recursive function to compute the number of leaf and non-leaf nodes
void computeLeafAndNonLeafCount(Node* root, int& leafCount, int& nonLeafCount) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        leafCount++;
    } else {
        nonLeafCount++;
    }

    computeLeafAndNonLeafCount(root->left, leafCount, nonLeafCount);
    computeLeafAndNonLeafCount(root->right, leafCount, nonLeafCount);
}

// Recursive function to compute the minimum element of a BST
int findMinimumElement(Node* root) {
    if (root == nullptr) {
        return INT_MAX;
    }

    int leftMin = findMinimumElement(root->left);
    int rightMin = findMinimumElement(root->right);

    return min(root->data, min(leftMin, rightMin));
}

// Recursive function for inorder traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Recursive function for preorder traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Iterative function for level order traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    Queue queue;
    queue.enqueue(root);

    while (!queue.isEmpty()) {
        Node* current = queue.getFront();
        queue.dequeue();

        cout << current->data << " ";

        if (current->left != nullptr) {
            queue.enqueue(current->left);
        }

        if (current->right != nullptr) {
            queue.enqueue(current->right);
        }
    }
}

void Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->left);
        Preorder(p->right);
    }
}
 
void Inorder(Node *p) {
    if (p){
        Inorder(p->left);
        cout << p->data << ", " << flush;
        Inorder(p->right);
    }
}
 
void Postorder(Node *p) {
    if (p){
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << ", " << flush;
    }
}

void getChildren(Node *t){
    Node *p = t;

    if(p->left != nullptr){
        cout<<"\nLeft Child Data of given node : \n"<<p->left->data<<"\n";
    }
    if(p->right != nullptr){
        cout<<"\nRight Child Data of given node : \n"<<p->right->data<<"\n";
    }
}
int main() {
    // Create a binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    //root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout<<"\nPreorder is: \n";
    Preorder(root);
    cout<<"\nPostorder is: \n";
    Postorder(root);
    cout<<"\nInorder is: \n";
    Inorder(root);
    // Find the inorder successor of a node
    Node* node = root->left->right; 
        cout<<endl; // Inorder successor of node with value 3 is 4
    getChildren(root);
    cout<<endl;
    Node* successor = findInorderSuccessor(root, node);

    if (successor) {
        cout << "\nInorder successor of " << node->data << " is " << successor->data << endl;
    } else {
        cout << "Inorder successor not found." << endl;
    }

    // Compute the height of the binary tree
    int height = computeHeight(root);
    cout << "Height of the binary tree: " << height << endl;

    // Compute the number of nodes having only right child
    int numRightChildOnly = computeNumRightChildOnly(root);
    cout << "Number of nodes having only right child: " << numRightChildOnly << endl;

    // Compute the number of leaf and non-leaf nodes
    int leafCount = 0;
    int nonLeafCount = 0;
    computeLeafAndNonLeafCount(root, leafCount, nonLeafCount);
    cout << "Number of leaf nodes: " << leafCount << endl;
    cout << "Number of non-leaf nodes: " << nonLeafCount << endl;

    // Compute the minimum element of a BST
    int minimumElement = findMinimumElement(root);
    cout << "Minimum element of the BST: " << minimumElement << endl;

    // Perform traversals
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    // Cleaning up memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
