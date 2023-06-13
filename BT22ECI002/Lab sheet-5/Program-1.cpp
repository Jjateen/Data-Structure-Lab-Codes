#include <iostream>
#include<cstring>
//#include <stack>

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
    //int peek(int index);
    int isFull();
    int empty();
    void display();
    int etop();
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
    } else {
        top++;
        S[top] = x;
    }
}
 
int stack::pop() {
    int x = 1;
    if (empty()){
        cout << "stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}
 
// int stack::peek(int index) {
//     int x = -1;
//     if (top-index+1 < 0 || top-index+1 == size){
//         cout << "Invalid position!" << endl;
//     } else {
//         x = S[top-index+1];
//     }
//     return x;
// }
 
int stack::isFull() {
    if (top == size-1){
        return 1;
    }
    return 0;
}
 
int stack::empty() {
    if (top == -1){
        return 1;
    }
    return 0;
}
 
void stack::display() {
    for (int i=top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
int stack::etop() {
    if (empty()){
        return -1;
    }
    return S[top];
}
 



int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
 
char* convert(char* infix){
    char* postfix = new char [strlen(infix) + 1];
 
    stack stk(strlen(infix));
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0'){
        
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
            
        } else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.etop())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.etop())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.etop();
                stk.pop();
            }
        }
    for(int k=0;k<j;k++)
        cout<<postfix[k]<<flush;
        cout<<"\n"<<flush;
    }
    
    while (! stk.empty() && stk.etop() != ')'){
        postfix[j++] = stk.etop();
        stk.pop();
        
    }
 
    postfix[j] = '\0';
 
    return postfix;
 
}
 
 
int main() {
 
    char infix[] = "((a+b)*c)-d^e^f";
    cout << convert(infix) << endl;

    return 0;
} 