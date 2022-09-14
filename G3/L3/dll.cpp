#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; // NULL, if this doesnt work
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
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

	void addAtHead(int val)
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
			this->head = newNode;
		}
		this->size++;
	}

	void addAtTail(int val)
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
			this->tail = newNode;
		}
		this->size++;
	}

	void addAtIndex(int index, int val)
	{
		if (index < 0 || index > this->size)
		{
			throw std::invalid_argument("Index out of range");
		}
		if (index == 0)
		{
			this->addAtHead(val);
		}
		else if (index == this->size - 1)
		{
			this->addAtTail(val);
		}
		else
		{
			ListNode *newNode = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
			this->size++;
		}
	}

	void printLL()
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
	LinkedList *ll = new LinkedList();
	ll->addAtHead(5);
	ll->printLL();
	ll->addAtHead(2);
	ll->printLL();
	ll->addAtTail(4);
	ll->printLL();
	ll->addAtTail(8);
	ll->printLL();
	ll->addAtIndex(0, 100);
	ll->printLL();
	ll->addAtIndex(2, 99);
	ll->printLL();
	ll->deleteAtIndex(0);
	ll->printLL();
	ll->deleteAtIndex(ll->size - 1);
	ll->printLL();
	ll->deleteAtIndex(1);
	ll->printLL();
	cout << ll->get(0);
	cout << ll->get(-1);
	cout << ll->get(3);
	return 0;
}