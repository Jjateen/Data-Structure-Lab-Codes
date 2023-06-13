#include <iostream>
using namespace std;
class Node
{
public:
 int data;
 Node *next;
};
class LinkedList
{
public:
 Node *first;
 LinkedList(){first=NULL;}
 LinkedList(int A[],int n);
 ~LinkedList();

 void Display();
 void Insert(int index,int x);
 int Delete(int index);
 int Length();
 //void LinkedList :: splitAtK(LinkedList l,Node* h1, Node* h2,int k);
 friend LinkedList operator+(LinkedList ,LinkedList );
};


LinkedList::LinkedList(int A[],int n)
{
 Node *last,*t;
 int i=0;

 first=new Node;
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
LinkedList::~LinkedList()
{
 Node *p=first;
 while(first)
 {
 first=first->next;
 delete p;
 p=first;
 }
}
void LinkedList::Display()
{
 Node *p=first;

 while(p)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
 cout<<endl;
}
int LinkedList::Length()
{
 Node *p=first;
 int len=0;

 while(p)
 {
 len++;
 p=p->next;
 }
 return len;
}
void LinkedList::Insert(int index,int x)
{
 Node *t,*p=first;

 if(index <0 || index > Length())
 return;
 t=new Node;
 t->data=x;
 t->next=NULL;

 if(index==0)
 {
 t->next=first;
 first=t;
 }
 else
 {
 for(int i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;
 }
}
int LinkedList::Delete(int index)

{
 Node *p,*q=NULL;
 int x=-1;

 if(index < 1 || index > Length())
 return -1;
 if(index==1)
 {
 p=first;
 first=first->next;
 x=p->data;
 delete p;
 }
 else
 {
 p=first;
 for(int i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;
 delete p;
 }
 return x;
}

LinkedList operator+(LinkedList l1, LinkedList l2){
    Node * p= l1.first;
    while(p->next){
        p = p->next;
    }
    p->next = l2.first;

    Node* newHead = l1.first;
    
    while (newHead){
        if(newHead->next)
        cout<<newHead->data<<" -> "<<flush;
        else
            cout<<newHead->data<<flush;
        newHead= newHead->next;
    }
    
}


int main()
{
        Node* h1=nullptr;
        Node* h2=nullptr;

    int A[]={1,2,3,4,5};
    int B[]={10,9,8,7,6};
    LinkedList l1(A,5);
    LinkedList l2(B,5);
 
    l1 + l2;
    cout<<"\n";
    l1.Display();

 return 0;
}