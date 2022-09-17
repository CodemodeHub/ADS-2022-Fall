#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};

struct Queue
{
	int size;
	Node *head;
	Node *tail;

	Queue() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	bool isEmpty() {

	}

	void push(int val) {

	}

	void pop() {

	}

	int front() {
		
	}
};

int main()
{

	return 0;
}