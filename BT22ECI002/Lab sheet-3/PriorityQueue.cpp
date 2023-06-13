#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

class Node{
    public:
    int data;
    int order;
    Node *next;
};

class Priority_Queue {
   private:
      Node *front;
      Node *rear;
   public:
      Priority_Queue(){
         front = nullptr;
      }

      void enqueue(int i, int p) {
         Node *t, *q;
         t = new Node;
         t->data = i;
         t->order = p;
         if (front == nullptr || p < front->order) {
            t->next= front;
            front = t;
         } else {
            q = front;
            while (q->next !=nullptr && q->next->order <= p)
               q = q->next;
               t->next = q->next;
               q->next = t;
         }
      }
      void dequeue() {
         Node *t;
         if(front == nullptr) //if queue is null
            cout<<"Queue Underflow\n";
         else {
            t = front;
            cout<<"Deleted item is: "<<t->data<<endl;
            front = front->next;
            delete t;
         }
      }
      void show(){
        Node *ptr;
         ptr = front;
         if (front == nullptr)
            cout<<"Queue is empty\n";
         else {
            cout<<"Queue is :\n";
            cout<<"Priority   :: Item\n";
            while(ptr != nullptr) {
               cout<<"  "<<ptr->order<<"            "<<ptr->data<<endl;
               ptr = ptr->next;
            }
         }
      }
};
int main() {
    int c, i, p;
    Priority_Queue pq;
        do{
   
            system("CLS");
            cout<<"\t\t\t===========================================\n";
            cout<<"\t\t\t|    Priority Queue Management System     |\n";
            cout<<"\t\t\t===========================================\n";
            cout<<"\t\t\t|                                         |";
            cout<<"\n\t\t\t| Enter <1> Input Data                    |"
                <<"\n\t\t\t| Enter <2> Delete Data                   |"
                <<"\n\t\t\t| Enter <3> to Display                    |"
                <<"\n\t\t\t| Enter <4> Exit                          |"
                <<"\n\t\t\t|                                         |"
                <<"\n\t\t\t===========================================";
            cout<<"\n\n\t\t\tEnter Your Choice:";
        cin>>c;
        switch(c) {
            case 1:
                cout<<"Input the item value to be added in the queue : ";
                cin>>i;
                cout<<"Enter its priority : ";
                cin>>p;
                pq.enqueue(i, p);
                break;
            case 2:
                pq.dequeue();
                system("PAUSE");
                break;
            case 3:
                pq.show();
                system("PAUSE");
                break;
            case 4:
                break;
            default:
            cout<<"Wrong choice\n";
        }
    }
    while(c != 4);
    return 0;
}