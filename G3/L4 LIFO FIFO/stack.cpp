#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

struct Stack
{
	int size;
	Node* top;

	Stack() {
		size = 0;
		top = nullptr;
	}

	void pop() {
		if (this->isEmpty()) {
			throw std::invalid_argument("error: stack is empty");
		} else {
			Node* toDelete = top;
			top = top->next;
			size--;
			delete (toDelete);
		}
	}

	int peek() {
		if (this->isEmpty()) {
			throw std::invalid_argument("error: stack is empty");
		} else {
			return top->val;
		}
	}

	void push(int val) {
		Node* newNode = new Node(val);
		if (this->isEmpty()) {
			top = newNode;
		} else {
			newNode->next = top;
			top = newNode;
		}
		size++;
	}

	bool isEmpty() {
		return size == 0;
	}
};

int main() {
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.peek() << endl;
	st.pop();

	cout << st.peek() << endl;
	st.pop();

	cout << st.peek() << endl;
	st.pop();

	cout << st.peek() << endl;
	st.pop();

	cout << st.size;
	return 0;
}