#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};
 
class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
    int getFront(){
        return front->data;
    }
};
 
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}
 
void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Queue Overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}
 
int Queue::dequeue() {
    int x = -1;
    Node* p;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
 
bool Queue::isEmpty() {
    if (front == nullptr){
        return true;
    }
    return false;
}
 
Queue::~Queue() {
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
 
void Queue::display() {
    Node* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
void BFS(int vtx, int A[][8], int n){
    Queue Q;
    int visited[8] {0};
 
    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.enqueue(vtx);
 
    // Explore
    while (!Q.isEmpty()){
        int u = Q.getFront();  // Vertex u for exploring
        Q.dequeue();
        for (int v=1; v<=n; v++){  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0){  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.enqueue(v);
            }
        }
    }
    cout << endl;
}

void DFS(int u, int A[][8], int n){
    static int visited[8] {0};
 
    if (visited[u] == 0){
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v=1; v<n; v++){
            if (A[u][v] == 1 && visited[v] == 0){
                DFS(v, A, n);
            }
        }
    }
}

bool isConnected(int A[][8], int n) {
    Queue Q;
    int visited[8]{ 0 };

    // Start BFS from vertex 1
    int startVertex = 1;
    cout << "Vertex: " << startVertex << " -> " << flush;
    visited[startVertex] = 1;
    Q.enqueue(startVertex);

    // Perform BFS traversal
    while (!Q.isEmpty()) {
        int u = Q.getFront();  // Vertex u for exploring
        Q.dequeue();
        for (int v = 1; v <= n; v++) {  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0) {  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.enqueue(v);
            }
        }
    }
    cout << endl;

    // Check if all vertices are visited
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            return false;
        }
    }

    return true;
}
 
int main (){
 
    int A[8][8] = {{0, 1, 1, 0, 0, 0, 1, 0},
                   {1, 0, 1, 1, 1, 0, 0, 0},
                   {1, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {1, 1, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
 
    cout << "\nDFS from : \nVertex: 4 -> " << flush;
    DFS(4, A, 8);
    cout << endl;
        if (isConnected(A, 8)) {
        cout << "\nThe graph is connected." << endl;
    }
    else {
        cout << "\nThe graph is not connected." << endl;
    }
    return 0;
}
	