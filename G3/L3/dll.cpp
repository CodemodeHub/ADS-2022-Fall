#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; // NULL, if this doesnt work
		this->prev = nullptr; // NULL, if this doesnt work
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
	}

	ListNode(int val, ListNode *prev, ListNode *next)
	{
		this->val = val;
		this->prev = prev;
		this->next = next;
	}
};

struct LinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	int get(int index)
	{
		if (index < 0 || index >= this->size)
		{
			throw std::invalid_argument("Index out of range");
		}
		ListNode *cur = this->head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	void push_front(int val)
	{
		ListNode *newNode = new ListNode(val);
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode->next = this->head;
			this->head->prev = newNode;
			this->head = newNode;
		}
		this->size++;
	}

	void push_back(int val)
	{
		ListNode *newNode = new ListNode(val);
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;
		}
		this->size++;
	}

	void insert(int index, int val)
	{
		if (index < 0 || index > this->size)
		{
			throw std::invalid_argument("Index out of range");
		}
		if (index == 0)
		{
			this->push_front(val);
		}
		else if (index == this->size)
		{
			this->push_back(val);
		}
		else
		{
			ListNode *newNode = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}
			ListNode *nextt = cur->next;
			cur->next = newNode;
			newNode->prev = cur;
			newNode->next = nextt;
			nextt->prev = newNode;
			this->size++;
		}
	}

	void print()
	{
		ListNode *cur = this->head;
		while (cur != nullptr)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	void deleteAtIndex(int index)
	{
		if (index < 0 || index > this->size)
		{
			throw std::invalid_argument("Index out of range");
		}
		if (index == 0)
		{
			this->head = this->head->next;
		}
		else if (index == this->size - 1)
		{
			ListNode *cur = this->head;
			while (cur->next != this->tail)
			{
				cur = cur->next;
			}
			cur->next = nullptr;
			this->tail = cur;
		}
		else
		{
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}
			cur->next = cur->next->next;
		}
		this->size--;
	}
};

int main()
{

	return 0;
}