#include <iostream>

using namespace std;
 

class CircularQueue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
                return;

    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
        return;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
 
void CircularQueue::display() {
    if(this->isEmpty()){
        cout<<"Blank\n";
        return;
    }

    else{
        int i = front + 1;
        do {
            cout << Q[i] << flush;
            if (i < rear) {
                cout << " <- " << flush;
            }
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout<<"\n";
    }
}
 
 
int main() {
 
    int Size;
    cout<<"Enter Size : ";
    cin>>Size;
    
    system("CLS");

    CircularQueue a(Size+1);
    stuscr:
	int i;
        system("CLS");
        cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|         Stack Management System         |\n";
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