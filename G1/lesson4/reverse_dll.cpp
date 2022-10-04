#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode* prev;
    ListNode() {
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    ListNode(int input_value) {
        this->value = input_value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

struct DoublyLinkedList {
    int size;
    ListNode* head;
    ListNode* tail;

    DoublyLinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addAtHead(int value) {
        ListNode* new_node = new ListNode(value);
        this->size++;
        if (!this->head) {
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
        if (!this->tail) {
            this->head = new_node;
            this->tail = new_node;
        } else {
            this->tail->next = new_node;
            new_node->prev = this->tail;
            this->tail = new_node;
        }
    }

    void addAtIndex(int index, int value) {
        if (index < 0 || index > this->size) {
            cout << "Error" << endl;
            return;
        } else if (index == 0) {
            this->addAtHead(value);
        } else if (index == this->size) {
            this->addAtTail(value);
        } else {
            ListNode* current = this->head;
            ListNode* new_node = new ListNode(value);
            for (int i = 0; i < index; i++)
                current = current->next;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            new_node->next = current;
            this->size++;
        }
    }

    int get(int index) {
        if (index >= this->size || index < 0) {
            return -1;
        } else {
            ListNode* current = this->head;
            for (int i = 0; i < index; i++)
                current = current->next;
            return current->value;
        }
    }

    void deleteByValue(int value) {
        this->size--;
        ListNode* current = this->head;
        while (current->value != value) {
            current = current->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= this->size || index < 0) {
            cout << "Error";
            return;
        } else if (index == 0) {
            this->size--;
            head = head->next;
            head->prev = nullptr;
        } else if (index == this->size - 1) {
            this->size--;
            ListNode* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete temp;

        } else {
            this->size--;
            ListNode* current = this->head;
            for (int i = 0; i < index; i++)
                current = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
    }

    void print() {
        ListNode* current = head;
        while (current) {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

ListNode* reverse_dll(ListNode* head) {
    ListNode* current = head;
    ListNode* next = current->next;
    ListNode* prev = nullptr;
    while (current) {
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        if (next)
            next = next->next;
    }
    return prev;
}


int main() {
    DoublyLinkedList* ll = new DoublyLinkedList();
    ll->addAtHead(5);
    ll->addAtTail(2);
    ll->addAtIndex(1, 3);
    ll->addAtIndex(1, 4);
    ll->addAtTail(1);
    ll->addAtTail(4);
    ll->print();
    cout << endl;
    ListNode* current = ll->tail;
    while (current) {
        cout << current->value << endl;
        current = current->prev;
    }
    // ListNode* reversedHead = reverse_dll(ll->head);
    // while(reversedHead) {
    //     cout<<reversedHead->value<<endl;
    //     reversedHead = reversedHead->next;
    // }
    return 0;
}