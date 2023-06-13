#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void insert(Node** head, int data) {
    Node* newNode = new Node(data);
    if (*head == nullptr) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

Node* deleteNodes(Node* head, int key) {
    if (head == nullptr)
        return nullptr;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr->next != head) {
        if (curr->data == key) {
            if (prev == nullptr) {  // If curr is the head node
                Node* last = head;
                while (last->next != head)
                    last = last->next;

                head = curr->next;
                last->next = head;
                delete curr;
                curr = head;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // Check for deletion of last node
    if (curr->data == key) {
        if (prev == nullptr) {  // Only one node is present
            delete curr;
            return nullptr;
        } else {
            prev->next = curr->next;
            delete curr;
            return prev->next;
        }
    }

    return head;
}

int main() {
    Node* head = nullptr;

    // Inserting elements into the circular linked list
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 3);
    insert(&head, 7);
    insert(&head, 9);

    cout << "Original Circular Linked List: ";
    display(head);

    int key = 7;
    head = deleteNodes(head, key);

    cout << "Updated Circular Linked List after deletion of nodes with data " << key << ": ";
    display(head);

    return 0;
}
