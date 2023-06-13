#include<iostream>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};

Node* first=nullptr;

void Display(Node *p)
{
 while(p)
 {  if(p->next)
    cout<<p->data<<" -> "<<flush;
    else
    cout<<p->data;
 p=p->next;
 }
}



void create(int A[],int n)
{
 int i;
 Node *t,*last;
 first=new Node;
 first->data=A[0];
 first->next=nullptr;
 last=first;

 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=nullptr;
 last->next=t;
 last=t;
 }
}

void Reverse(Node *p)
{
 Node *q=nullptr,*r=nullptr;

 while(p)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}
//Recursive
// void Reverse(Node *q,Node *p)
// {
//  if(p)
//  {
//  Reverse3(p,p->next);
//  p->next=q;
//  }
//  else
//  first=q;
// }

void length(Node *h){
    Node* p = h;
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    cout<<"\nNo. of Nodes = "<<c<<"\n";
}
void splitAtK(Node* h1, Node* h2,int k){
    Node* p = h1;
    for(int i = 0; i<k; i++){
        p=p->next;
    }
    h2 = p->next;
    p->next = nullptr;
    while (h1){
        if(h1->next)
        cout<<h1->data<<" -> "<<flush;
        else
            cout<<h1->data<<flush;
        h1= h1->next;
    }
    cout<<"\t";
    while (h2){
        if(h2->next)
        cout<<h2->data<<" -> "<<flush;
        else
            cout<<h2->data<<flush;
        h2= h2->next;
    }
    cout<<"\n";

}

Node* searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main()
{
    Node *h2 = nullptr;
 int A[]={10,20,40,50,60};
 create(A,5);

 Display(first);
  cout<<"\n";

int key = 60;
    Node* result = searchNode(first, key);

    if (result != nullptr) {
        cout << "Node with key " << key << " found: " << result->data << endl;
    } else {
        cout << "Node with key " << key << " not found." << endl;
    }

 splitAtK(first,h2,1);
 Reverse(first);
 cout<<"\n";
 length(first);
 Display(first);
 cout<<"\n";
 return 0;
}