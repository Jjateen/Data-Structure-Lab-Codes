#include<iostream>
using namespace std;
 
class Queue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
        return;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int Queue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
        return;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
void Queue::display() {
    for (int i=front+1; i<=rear; i++){
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
    int Size;
    cout<<"Enter Size : ";
    cin>>Size;
    
    system("CLS");

    Queue a(Size);
    stuscr:
	int i;
        system("CLS");
        cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|         Queue Management System         |\n";
		cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|                                         |"
            <<"\n\t\t\t| Enter <1> Enqueue Data                  |"
            <<"\n\t\t\t| Enter <2> Dequeue Element               |"
			<<"\n\t\t\t| Enter <3> isFull                        |"
			<<"\n\t\t\t| Enter <4> isEmpty                       |"
            <<"\n\t\t\t| Enter <0> to Display Data               |"
			<<"\n\t\t\t|                                         |"
			<<"\n\t\t\t===========================================";
		cout<<"\n\n\t\t\tEnter Your Choice : ";
		cin>>i;
		switch(i)
		{
			case 1 :
                int e;
                cout<<"Enter Element : ";
                cin>>e;
                cout<<"\n";
				a.enqueue(e);
				goto stuscr;
				break;
			case 2 :
				cout<<a.dequeue()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
			case 3 :
				cout<<a.isFull()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
            case 4 :
				cout<<a.isEmpty()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
            case 0 :
				a.display();
                system("PAUSE");
				goto stuscr;
				break;
			default :
				cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
				system("PAUSE");
                goto stuscr;
				break;
		}
    
    return 0;
}