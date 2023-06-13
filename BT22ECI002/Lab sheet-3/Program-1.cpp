#include <iostream>
using namespace std;
 
class stack{
private:
    int size;
    int top;
    int* S;
public:
    stack(int size);
    ~stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
};
 
stack::stack(int size) {
    this->size = size;
    top = -1;
    S = new int[size];
}
 
stack::~stack() {
    delete[] S;
}
 
void stack::push(int x) {
    if (isFull()){
        cout << "stack Overflow!" << endl;
	return;
    } else {
        top++;
        S[top] = x;
    }
}
 
int stack::pop() {
    int x = 1;
    if (isEmpty()){
        cout << "stack Underflow!" << endl;
        return;
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
int stack::peek(int index) {
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}
 
int stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int stack::isEmpty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void stack::display() {
    if(isEmpty()){
        cout<<"UnderFlow\n";
        return;
    }
    else{
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }}
    cout << endl;
}
 
int stack::stackTop() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}
 
 
int main() {
    int Size;
    cout<<"Enter Size : ";
    cin>>Size;
    
    system("CLS");
    stack a(Size); //default Size is x100
    stuscr:
	int i;
        system("CLS");
        cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|         Stack Management System         |\n";
		cout<<"\t\t\t===========================================\n";
		cout<<"\t\t\t|                                         |"
            <<"\n\t\t\t| Enter <1> Push Data                     |"
            <<"\n\t\t\t| Enter <2> Pop Element                   |"
            <<"\n\t\t\t| Enter <3> Peek                          |"
			<<"\n\t\t\t| Enter <4> isFull                        |"
			<<"\n\t\t\t| Enter <5> isEmpty                       |"
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
				a.push(e);
				goto stuscr;
				break;
			case 2 :
				cout<<a.pop()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
			case 3 :
                int id;
                cout<<"Enter Index to Peek : ";
				a.peek(id);
                system("PAUSE");
				goto stuscr;
				break;
			case 4 :
				cout<<a.isFull()<<"\n";
                system("PAUSE");
				goto stuscr;
				break;
            case 5 :
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
	