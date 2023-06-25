#include <iostream>
#include <climits>

using namespace std;

class Node {
public:
    int vertex;
    int weight;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int v, int w);
    int dequeue();
    bool isEmpty();
    void display();
};

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::enqueue(int v, int w) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Queue Overflow" << endl;
    } else {
        t->vertex = v;
        t->weight = w;
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
    int v = -1;
    int w = -1;
    Node* p;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    } else {
        p = front;
        front = front->next;
        v = p->vertex;
        w = p->weight;
        delete p;
    }
    return v;
}

bool Queue::isEmpty() {
    if (front == nullptr) {
        return true;
    }
    return false;
}

void Queue::display() {
    Node* p = front;
    while (p) {
        cout << "(" << p->vertex << ", " << p->weight << ") ";
        p = p->next;
    }
    cout << endl;
}

void Dijkstra(int** graph, int n, int source) {
    int* distance = new int[n];
    bool* visited = new bool[n];
    int* parent = new int[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    distance[source] = 0;
    visited[source] = true;
    parent[source] = -1;

    Queue q;
    q.enqueue(source, 0);

    while (!q.isEmpty()) {
        int u = q.dequeue();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                int newDistance = distance[u] + graph[u][v];
                if (newDistance < distance[v]) {
                    distance[v] = newDistance;
                    parent[v] = u;
                }
                q.enqueue(v, distance[v]);
            }
        }

        visited[u] = true;
    }

    // Print the shortest path distances and paths
    cout << "Vertex\tDistance\tPath" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << distance[i] << "\t\t";
        int j = i;
        while (j != -1) {
            cout << j;
            j = parent[j];
            if (j != -1) {
                cout << " <- ";
            }
        }
        cout << endl;
    }

    delete[] distance;
    delete[] visited;
    delete[] parent;
}

int main() {
    int n = 6; // Number of vertices

    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Initialize all distances to 0 (no edge)
        }
    }

    // Add edges and their weights to the graph
    graph[0][1] = 2;
    graph[0][2] = 4;
    graph[1][2] = 1;
    graph[1][3] = 7;
    graph[2][3] = 3;
    graph[2][4] = 5;
    graph[3][4] = 2;
    graph[3][5] = 1;
    graph[4][5] = 6;

    int source = 0; // Source vertex

    // Run Dijkstra's algorithm
    Dijkstra(graph, n, source);

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
