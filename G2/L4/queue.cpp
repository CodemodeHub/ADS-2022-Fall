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
		if (this->isEmpty()) {
			throw std::invalid_argument("queue is empty");
		} else {
			Node *toDel = beti;
			beti = beti->next;
			delete (toDel);
		}
		size--;
	}

	int front() {
		return beti->val;
	}

	void push(int val) {
		if (this->isEmpty()) {
			Node *newNode = new Node(val);
			beti = newNode;
			koteni = newNode;
		} else {
			Node *newNode = new Node(val);
			koteni->next = newNode;
			koteni = newNode;
		}
		size++;
	}

	bool isEmpty() {
		return size == 0;
	}

};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.push(10);
	q.push(10);
	q.push(10);
	while (!q.isEmpty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}