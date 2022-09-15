#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode() {
        this->value = 0;
        this->next = nullptr;
    }
    ListNode(int input_value) {
        this->value = input_value;
        this->next = nullptr;
    }
};

struct Queue {
    int size;
    ListNode* front;
    ListNode* back;
    Queue() {
        this->size = 0;
        this->front = nullptr;
        this->back = nullptr;
    }
    void push(int value) {
        ListNode* newNode = new ListNode(value);
        if(this->size == 0) {
            this->front = newNode;
            this->back = newNode;
        } else {
            this->back->next = newNode;
            this->back = newNode;
        }
        this->size++;
    }
    int pop() {
        if(this->size == 0) {
            cout<<"Queue is empty\n";
            return INT_MIN;
        } else {
            int result = this->front->value;
            ListNode* temp = this->front;
            this->front = this->front->next;
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
    Queue* q = new Queue();
    cout<<q->pop()<<endl;
    q->push(5);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(1);
    while(!q->isEmpty()){
        cout<<q->pop()<<endl;
    }
    return 0;
}