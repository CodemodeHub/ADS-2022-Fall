#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int x) {
        value = x;
        next = nullptr;
    }
    void print() {
        Node *cur = this;
        while(cur) {
            cout<<cur->value<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

struct LinkedList {
    Node* head;
    int size;
    
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    Node* get_tail() {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur;
    }

    void push_back(int value) {
        Node* node = new Node(value);
        size++;
        if(!head) {
            head = node;
            return;
        } 
        Node* tail = get_tail();
        tail->next = node;
    }

    void push_front(int value) {
        Node* node = new Node(value);
        size++;
        if(!head) {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void insert(int value, int index) {
        if(index < 0 || index >= size) {
            cout<<"Error, there is no such index\n";
            return;
        }
        if(index == 0) {
            push_front(value);
        } else if(index == size) {
            push_back(value);
        } else {
            Node* node = new Node(value);
            size++;
            Node* cur = head;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;
        }
    }

    bool isEmpty() {
        // return head == nullptr;
        return size == 0;
    }

    void pop_back() {
        if(isEmpty()) {
            cout<<"The linked list is empty!\n";
            return;
        }
        Node* cur = head;
        while(cur->next->next) {
            cur = cur->next;
        }
        Node* tail = cur->next;
        size--;
        delete tail;
        cur->next = nullptr;
    }

    void pop_front() {
        if(isEmpty()) {
            cout<<"The linked list is empty!\n";
            return;
        }
        Node * temp = head;
        size--;
        head = head->next;
        delete temp;
    }

    void removeByIndex(int index) {
        if(isEmpty()) {
            cout<<"The linked list is empty!\n";
            return;
        }
        if(index == 0) {
            pop_front();
        } else if(index == size - 1) {
            pop_back();
        } else {
            Node* cur = head;
            size--;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }

    int search(int value) {
        Node* cur = head;
        int index = 0;
        while(cur) {
            if(cur->value == value) {
                return index; 
            }
            index++;
            cur = cur->next;
        }
        return -1;
    } 

    void removeAllValues(int value) {
        if(isEmpty()) {
            cout<<"The linked list is empty!\n";
            return;
        }
        while(search(value) != -1) {
            int removeIndex = search(value);
            removeByIndex(removeIndex);
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        Node* next = nullptr;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    
    void print() {
        Node* cur = head;
        while(cur) {
            cout<<cur->value<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

Node* merge(Node* lHead, Node* rHead) {
    Node* dummy = new Node(0);
    Node* cur = dummy;
    Node* lCur = lHead, *rCur = rHead;
    while(lCur && rCur) {
        if(lCur->value < rCur->value) {
            cur->next = new Node(lCur->value);
            lCur = lCur->next;
        } else {
            cur->next = new Node(rCur->value);
            rCur = rCur->next;
        }
        cur = cur->next;
    }
    if(lCur)
        cur->next = lCur; 
    if(rCur)
        cur->next = rCur;
    return dummy->next;
}

Node* sort(Node* head) {
    if(!head->next || !head){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second_head = slow->next;
    Node* lHead = sort(second_head);
    slow->next = nullptr;
    Node* rHead = sort(head);
    return merge(lHead, rHead);
}

int main() {
    LinkedList ll;
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.insert(1, 0);
    ll.insert(9, 4);
    ll.insert(3, 2);
    ll.push_back(5);
    ll.push_front(5);
    /*
    1 5 6 7 8
    */
    ll.print();
    LinkedList sortedLL;
    Node* newHead = sort(ll.head);
    sortedLL.head = newHead;
    sortedLL.print();
    // sortedLL.print();
    // ll.reverse();
    // ll.removeAllValues(5);
    // ll.removeByIndex(1);
    // ll.pop_back();
    // ll.pop_front();
    // ll.removeByIndex(2);
    // ll.print();
    return 0;
}

/*
1. Insert at random pos +
2. push back +
3. push front +
4. pop back +
5. pop front +
6. empty() +
7. reverse +
8. sort* +
9. remove at random pos + 
10. search for val +
11. replace 
12. swap 
13. shift left  
14. shift right  
*/