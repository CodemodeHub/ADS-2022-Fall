#include<iostream>
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
    ListNode(int input_value, ListNode* next_node) {
        this->value = input_value;
        this->next = next_node;
    }
};

struct LinkedList {
    int size;
    ListNode* head;
    ListNode* tail;

    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addAtHead(int value) {
        ListNode* new_node = new ListNode(value);
        this->size++;
        if(!this->head) {
            this->head = new_node;
            this->tail = new_node;
        } else {
            new_node->next = this->head;
            this->head = new_node;
        }
    }

    void addAtTail(int value) {
        ListNode* new_node = new ListNode(value);
        this->size++;
        if(!this->tail) {
            this->head = new_node;
            this->tail = new_node;
        } else {
            this->tail->next = new_node;
            this->tail = new_node;
        }
    }

    void addAtIndex(int index, int value) {
        if(index < 0 || index > this->size) {
            cout<<"Error"<<endl;
            return ;
        } else if(index == 0) {
            this->addAtHead(value);
        } else if(index == this->size) {
            this->addAtTail(value);
        } else {
            ListNode* current = this->head;
            ListNode* new_node = new ListNode(value);
            for(int i = 0; i < index - 1; i++)
                current = current->next;
            new_node->next = current->next;
            current->next = new_node;
            this->size++;
        }
    }

    int get(int index) {
        if(index >= this->size || index < 0) {
            return -1;
        } else {
            ListNode* current = this->head;
            for(int i = 0; i < index; i++) 
                current = current->next;
            return current->value;
        }
    }
    
    void print() {
        ListNode* current = head;
        while(current) {
            cout<<current->value<<endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList* ll = new LinkedList();
    ll->addAtHead(5);
    ll->addAtTail(2);
    ll->addAtIndex(1, 3);
    ll->addAtIndex(1 ,4);
    ll->addAtTail(1);
    ll->print();
    cout<<ll->get(3)<<endl;
    cout<<ll->get(1)<<endl;
    return 0;
}