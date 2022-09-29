#include <iostream>
using namespace std;

struct Node
{
	char value;
	Node *prev;

	Node(char value)
	{
		this->value = value;
		this->prev = nullptr;
	}
};

struct Stack
{
	Node *top;
	int size;
	Stack()
	{
		this->top = nullptr;
	}

	void push(char value)
	{
		Node *newNode = new Node(value);
		if (this->top == nullptr)
		{
			this->top = newNode;
		}
		else
		{
			newNode->prev = this->top;
			this->top = newNode;
		}
		this->size++;
	}

	char pop()
	{
		if (this->top == nullptr)
		{
			cout << "Stack is empty" << endl;
			return '-';
		}
		else
		{
			char temp = this->top->value;
			this->top = this->top->prev;
			this->size--;
			return temp;
		}
	}

	void display()
	{
		if (this->top == nullptr)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			Node *temp = this->top;
			while (temp != nullptr)
			{
				cout << temp->value << " ";
				temp = temp->prev;
			}
			cout << endl;
		}
	}

	bool isEmpty()
	{
		return this->size == 0;
	}
};

int main()
{
	string s;
	cin >> s;
	Stack *st = new Stack();
	string ans;
	for (auto c : s)
	{
		if (c != ']')
		{
			st->push(c);
		}
		else
		{
			string temp = "";
			while (!st->isEmpty() && st->top->value != '[')
			{
				temp = st->top->value + temp;
				st->pop();
			}
			if (!st->isEmpty())
			{
				st->pop();
				string k = "";
				while (!st->isEmpty() and isdigit(st->top->value))
				{
					k = st->top->value + k;
					st->pop();
				}
				int digit = stoi(k);
				while (digit--)
				{
					for (char x : temp)
						st->push(x);
				}
			}
		}
	}
	while (!st->isEmpty())
		ans = st->pop() + ans;
	cout << ans << endl;
	return 0;
}