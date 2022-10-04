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
        if (this->top == nullptr) {
            this->top = newNode;
            this->size++;
        } else {
            newNode->prev = this->top;
            this->top = newNode;
            this->size++;
        }
    }
    int pop() {
        if (this->top == nullptr) {
            cout << "Stack is empty\n";
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

int main() {
    Stack* stack = new Stack();
    cout << stack->pop() << endl;
    stack->push(5);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(1);
    while (!stack->isEmpty()) {
        cout << stack->pop() << endl;
    }
    return 0;
}