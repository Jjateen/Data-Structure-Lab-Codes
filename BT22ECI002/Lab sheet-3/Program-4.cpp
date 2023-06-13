#include <iostream>

using namespace std;
 
class DEQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;
 
public:
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};
 
 DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
DEQueue::~DEQueue() {
    delete [] Q;
}
 
bool DEQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool DEQueue::isFull() {
    if (rear == size - 1){
        return true;
    }
    return false;
}
 
void DEQueue::enqueueFront(int x) {
    if (front == -1){
        cout << "DEQueue Overflow" << endl;
    } else {
        Q[front] = x;
        front--;
    }
}
 
void DEQueue::enqueueRear(int x) {
    if (isFull()){
        cout << "DEQueue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int DEQueue::dequeueFront() {
    int x = -1;
    if (isEmpty()){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[front];
        front++;
    }
    return x;
}
 
int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}
 
void DEQueue::display() {
    for (int i=front+1; i<=rear; i++) {
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

    DEQueue a(Size);
    stuscr:
	int i;
        system("CLS");
        cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|        Dequeue Management System        |\n";
		cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|                                         |"
            <<"\n\t\t\t| Enter <1> Enqueue Data in Front         |"
            <<"\n\t\t\t| Enter <2> Enqueue Data in Rear          |"
            <<"\n\t\t\t| Enter <3> Dequeue Element off Front     |"
            <<"\n\t\t\t| Enter <4> Dequeue Element off Rear      |"
			<<"\n\t\t\t| Enter <5> isFull                        |"
			<<"\n\t\t\t| Enter <4> isEmpty                       |"
            <<"\n\t\t\t| Enter <0> to Display Data               |"
			<<"\n\t\t\t|                                         |"
			<<"\n\t\t\t===========================================";
		cout<<"\n\n\t\t\tEnter Your Choice : ";
		cin>>i;
		switch(i)
		{
			case 1 :
                int e0;
                cout<<"Enter Element : ";
                cin>>e0;
                cout<<"\n";
				a.enqueueFront(e0);
                system("PAUSE");

				goto stuscr;
				break;
            case 2 :
                int e1;
                cout<<"Enter Element : ";
                cin>>e1;
                cout<<"\n";
				a.enqueueRear(e1);
				goto stuscr;
				break;
			case 3 :
            a.dequeueFront();
				cout<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
            case 4 :
            a.dequeueRear();
				cout<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
			case 5 :
				cout<<a.isFull()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
            case 6 :
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