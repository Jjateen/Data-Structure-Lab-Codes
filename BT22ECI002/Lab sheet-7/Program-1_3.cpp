#include <iostream>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
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

//long int stack 
class stack {
private:
    class StackNode {
        public: 
        long int data;
        StackNode* next;

        StackNode(long int value, StackNode* nextNode = nullptr) {
            data = value;
            next = nextNode;
        }
    };

    StackNode* top;

public:
    stack() {
        top = nullptr;
    }

    ~stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(long int value) {
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

    long int getTop() {
        if (isEmpty()) {
            return -1;
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


class Tree{
private:
    Node* root;
public:
    Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    int Height(Node* p);
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
};
 
Tree::Tree() {
    root = nullptr;
}
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    Queue q;
 
    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.getFront();
        q.dequeue();
 
        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
 
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 
void Tree::Levelorder(Node *p) {
    Queue q;
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.getFront();
        q.dequeue();
 
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
 
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}
 
void Tree::iterativePreorder(Node *p) {
    Stack stk;
    while (p != nullptr || ! stk.isEmpty()){
        if (p != nullptr){
            cout << p->data << ", " << flush;
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.getTop();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}
 
void Tree::iterativeInorder(Node *p) {
    Stack stk;
    while (p != nullptr || ! stk.isEmpty()){
        if (p != nullptr){
            stk.push(p);
            p = p->lchild;
        } else {
            p = stk.getTop();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}
 
void Tree::iterativePostorder(Node *p) {
    stack stk;
    long int temp;
    while (p != nullptr || ! stk.isEmpty()){
        if (p != nullptr){
            stk.push((long int)p);
            p = p->lchild;
        } else {
            temp = stk.getTop();
            stk.pop();
            if (temp > 0){
                stk.push(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}
 
 
int main() {
 
    Tree bt;
 
    bt.CreateTree();
    cout << endl;
 
    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;
 
    cout << "Height: " << bt.Height() << endl;
 
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();
 
    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();
 
    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();
 
    return 0;
}
	