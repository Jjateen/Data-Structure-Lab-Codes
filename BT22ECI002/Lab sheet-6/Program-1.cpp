#include <iostream>

using namespace std;

// Node structure for a linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    Node* mergedList = nullptr;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = merge(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = merge(list1, list2->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitList(Node* head, Node** front, Node** back) {
    Node* slow = head;
    Node* fast = head->next;

    // Move fast pointer by two and slow pointer by one
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = nullptr;
}

// Merge sort function for linked lists
void mergeSort(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }

    Node* front;
    Node* back;

    splitList(*head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *head = merge(front, back);
}

// Function to insert a node at the end of a linked list
void insert(Node** head, int data) {
    Node* newNode = new Node(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements into the linked list
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 1);
    insert(&head, 6);
    insert(&head, 3);

    cout << "Original Linked List: ";
    display(head);

    // Sorting the linked list using merge sort
    mergeSort(&head);

    cout << "Sorted Linked List: ";
    display(head);

    return 0;
}
