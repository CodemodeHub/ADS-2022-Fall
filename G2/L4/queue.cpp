#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;

	Node(int val)
	{
		this->val = val;
	}
};

struct Queue {
	Node *beti;
	Node *koteni;
	int size;

	Queue() {
		beti = nullptr;
		koteni = nullptr;
		size = 0;
	}

	void pop() {

	}

	int front() {

	}

	void push(int val) {

	}

	bool isEmpty() {

	}

};

int main()
{

	return 0;
}