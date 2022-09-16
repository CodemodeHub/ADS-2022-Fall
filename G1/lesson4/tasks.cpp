#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* prev;
    ListNode() {
        this->value = 0;
        this->prev = nullptr;
    }
    ListNode(int input_value) {
        this->value = input_value;
        this->prev = nullptr;
    }
};

struct Stack {
    int size;
    ListNode* top;
    Stack() {
        this->size = 0;
        this->top = nullptr;
    }
    void push(int value) {
        ListNode* newNode = new ListNode(value);
        if(this->top==nullptr) {
            this->top = newNode;
            this->size++;
        } else {
            newNode->prev = this->top;
            this->top = newNode;
            this->size++;
        }
    }
    int pop() {
        if(this->top == nullptr) {
            cout<<"Stack is empty\n";
            return INT_MIN;
        } else {
            int result = this->top->value;
            ListNode* temp = this->top;
            this->top = this->top->prev;
            delete temp;
            this->size--;
            return result;
        }
    }
    bool isEmpty() {
        return this->size == 0;
    }
};

int calPoints(vector<string>& ops) {
    Stack* records = new Stack();
    for(int i = 0; i < ops.size(); i++) {
        string operation = ops[i];
        if(operation == "C") {
            records->pop();
        } else if(operation == "D") {
            records->push(records->top->value * 2);
        } else if(operation == "+") {
            int last = records->pop();
            int pre_last = records->top->value;
            records->push(last);
            records->push(last + pre_last);
        } else {
            records->push(stoi(operation));
        }
    }
    int result = 0;
    while(!records->isEmpty()) {
        result += records->pop();
    }
    return result;
}

int postfix(vector<string> ops) {
    Stack* stack = new Stack();
    for(int i = 0; i < ops.size(); i++) {
        string operation = ops[i];
        if(operation == "+") {
            int first = stack->pop();
            int second = stack->pop();
            stack->push(first + second);
        } else if(operation == "-") {
            int first = stack->pop();
            int second = stack->pop();
            stack->push(second - first);
        } else if(operation == "*") {
            int first = stack->pop();
            int second = stack->pop();
            stack->push(second * first);
        } else {
            stack->push(stoi(operation));
        }
    }
    return stack->pop();
}

int main() {
    vector<string> input = {"8", "9", "5", "+", "4", "*", "+"};
    cout<<postfix(input)<<endl;
    return 0;
}