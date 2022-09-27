#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;

	Node(int value)
	{
		this->value = value;
		this->next = nullptr;
	}
};

struct Queue
{
	Node *front;
	Node *back;
	int size;
	Queue()
	{
		this->front = nullptr;
		this->back = nullptr;
		this->size = 0;
	}

	void push(int value)
	{
		Node *newNode = new Node(value);
		if (this->front == nullptr)
		{
			this->front = newNode;
			this->back = newNode;
		}
		else
		{
			this->back->next = newNode;
			this->back = newNode;
		}
		this->size++;
	}

	Node *pop()
	{
		if (this->front == nullptr)
		{
			cout << "Queue is empty" << endl;
			return nullptr;
		}
		else
		{
			Node *temp = this->front;
			this->front = this->front->next;
			this->size--;
			return temp;
		}
	}

	void print()
	{
		if (this->front == nullptr)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			Node *temp = this->front;
			while (temp != nullptr)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	bool isEmpty()
	{
		return this->front == nullptr;
	}
};

int main()
{
	Queue q;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int x = 1;
	while (q.size != 1) {
		if (x == k) {
			q.pop();
			x = 1;
		} else {
			Node* temp = q.pop();
			q.push(temp->value);
			x++;
		}
	}
	cout << q.front->value;
	return 0;
}