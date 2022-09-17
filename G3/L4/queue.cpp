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

	Queue()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void push(int val)
	{
		Node *newNode = new Node(val);
		if (this->isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void pop()
	{
		if (this->isEmpty())
		{
			throw std::invalid_argument("error: queue is empty");
		}
		else
		{
			Node *toDel = head;
			head = head->next;
			size--;
			delete (toDel);
		}
	}

	int front()
	{
		if (this->isEmpty())
		{
			throw std::invalid_argument("error: queue is empty");
		}
		else
		{
			return head->val;
		}
	}
};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.isEmpty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}