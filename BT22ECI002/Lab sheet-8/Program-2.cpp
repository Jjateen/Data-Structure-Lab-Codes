#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
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
};

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Queue Overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr) {
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
    if (isEmpty()) {
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
    if (front == nullptr) {
        return true;
    }
    return false;
}

Queue::~Queue() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::display() {
    Node* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void BFS(int vtx, int** graph, int n, bool* visited) {
    Queue Q;
    visited[vtx] = true;
    Q.enqueue(vtx);

    while (!Q.isEmpty()) {
        int u = Q.dequeue();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                Q.enqueue(v);
            }
        }
    }
}

bool isConnected(int** graph, int n) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    BFS(0, graph, n, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }

    delete[] visited;
    return true;
}

int main() {
    int n = 8; // Number of vertices

    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Initialize all edges to 0 (no edge)
        }
    }

    // Add edges to the graph
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;
    graph[4][5] = 1;
    graph[5][4] = 1;
    graph[5][6] = 1;
    graph[6][5] = 1;
    graph[6][7] = 1;
    graph[7][6] = 1;

    bool connected = isConnected(graph, n);

    if (connected) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
