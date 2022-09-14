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

	void reverseList()
	{
		this->tail = this->head;
		ListNode *prev = nullptr, *cur = this->head;
		while (cur != nullptr)
		{
			ListNode *nextt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nextt;
		}
		this->head = prev;
	}
};


int main()
{
	LinkedList ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ll.addAtTail(x);
	}
	ll.print();
	ll.reverseList();
	ll.print();
	return 0;
}

// 5
// 1 2 3 4 5