#include <iostream>
#include <cstring>

using namespace std;

class stack {
private:
    int size;
    int top;
    char* S;

public:
    stack(int size);
    ~stack();
    void push(char x);
    char pop();
    int isFull();
    int empty();
    void display();
    char etop();
};

stack::stack(int size) {
    this->size = size;
    top = -1;
    S = new char[size];
}

stack::~stack() {
    delete[] S;
}

void stack::push(char x) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        S[top] = x;
    }
}

char stack::pop() {
    char x = '\0';
    if (empty()) {
        cout << "Stack Underflow!" << endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

int stack::isFull() {
    if (top == size - 1) {
        return 1;
    }
    return 0;
}

int stack::empty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

void stack::display() {
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

char stack::etop() {
    if (empty()) {
        return '\0';
    }
    return S[top];
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return 0;
    }
    return 1;
}

int outPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 3;
    } else if (x == '^') {
        return 6;
    } else if (x == '(') {
        return 7;
    } else if (x == ')') {
        return 0;
    }
    return -1;
}

int inPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 2;
    } else if (x == '*' || x == '/') {
        return 4;
    } else if (x == '^') {
        return 5;
    } else if (x == '(') {
        return 0;
    }
    return -1;
}

char* convert(char* infix) {
    int length = strlen(infix);
    char* prefix = new char[length + 1];
    stack stk(length);
    int j = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperand(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            stk.push(infix[i]);
        } else if (infix[i] == '(') {
            while (!stk.empty() && stk.etop() != ')') {
                prefix[j++] = stk.pop();
            }
            if (!stk.empty()) {
                stk.pop(); // Pop the remaining ')'
            }
        } else {
            while (!stk.empty() && outPrecedence(infix[i]) < inPrecedence(stk.etop())) {
                prefix[j++] = stk.pop();
            }
            stk.push(infix[i]);
        }
    }

    while (!stk.empty()) {
        prefix[j++] = stk.pop();
    }

    prefix[j] = '\0';

    // Reverse the prefix string
    int start = 0;
    int end = j - 1;
    while (start < end) {
        swap(prefix[start], prefix[end]);
        start++;
        end--;
    }

    return prefix;
}

int main() {
    char infix[] = "((a+b)*c)-d^e^f";
    cout << "Infix Expression: " << infix << endl;
    char* prefix = convert(infix);
    cout << "Prefix Expression: " << prefix << endl;

    delete[] prefix;

    return 0;
}
