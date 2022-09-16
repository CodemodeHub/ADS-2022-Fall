#include <iostream>
using namespace std;


struct Node {
	int val;
	Node *next;

	Node(int val) {
		this->val = val;
	}
};


struct Stack {
	Node *top;

	Stack() {
		this->top = nullptr;
	}

	void push(int val) {
		if (this->isEmpty()) {
			top = new Node(val);
		} else {
			Node* newNode = new Node(val);
			newNode->next = top;
			top = newNode;
		}
	}

	void pop() {
		if (this->isEmpty()) {
			throw std::invalid_argument("the stack is empty!!!");
		} else {
			Node *toDelete = top;
			top = top->next;
			delete (toDelete);
		}
	}

	int top() {
		return top->val;
	}

	bool isEmpty() {
		return top == nullptr;
	}
};

int main() {
	// Stack *st = new Stack();
	Stack st;
	int n;
	cin >> n;
	while (n--) {
		
	}

	return 0;
}