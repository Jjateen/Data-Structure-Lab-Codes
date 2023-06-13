#include <iostream>
using namespace std;

class Node {
    public:
    string name;
    string dob;
    int age;
    Node* next;
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() : rear(nullptr) {}

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(string name, string dob, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->dob = dob;
        newNode->age = age;

        if (isEmpty()) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Person enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No person to dequeue." << endl;
            return;
        }

        Node* temp = rear->next;

        if (rear->next == rear) {
            rear = nullptr;
        } else {
            rear->next = rear->next->next;
        }

        cout << "Person dequeued successfully." << endl;
        delete temp;
    }

    int countSeniorCitizens() {
        if (isEmpty()) {
            return 0;
        }

        int count = 0;
        Node* current = rear;

        do {
            if (current->age >= 60) {
                count++;
            }
            current = current->next;
        } while (!(current == rear));

        return count;
    }
};

int main() {
    CircularQueue queue;

    // Enqueue persons
    queue.enqueue("John", "1990-01-01", 61);
    queue.enqueue("Alice", "1985-06-12", 29);
    queue.enqueue("David", "1975-11-30", 46);
    queue.enqueue("Sarah", "1950-03-15", 71);

    // Dequeue a person
    queue.dequeue(); //decreasing a senior citizen

    // Count senior citizens
    int seniorCitizenCount = queue.countSeniorCitizens();
    cout << "Senior Citizens in the queue: " << seniorCitizenCount << endl;

    return 0;
}
