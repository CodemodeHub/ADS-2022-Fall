#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

struct DoublyLinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	DoublyLinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_front(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			temp->next = this->head;
			this->head->prev = temp;
			this->head = temp;
		}
	}

	void push_back(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			temp->prev = this->tail;
			this->tail = temp;
		}
	}

	void removeEveryKthNode(int k)
	{
		ListNode *cur = head;
		int index = 1;
		while (cur != nullptr)
		{
			if (index % k == 0)
			{
				if (cur->next == nullptr)
				{
					cur->prev->next = nullptr;
				}
				else
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
				}
			}
			cur = cur->next;
			index++;
		}
	}

	void print()
	{
		ListNode *cur = head;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << '\n';
	}
};

int main()
{
	int n, m, k;
	cin >> n >> k;
	DoublyLinkedList dll;
	while (n--)
	{
		cin >> m;
		dll.push_back(m);
	}
	dll.removeEveryKthNode(k);
	dll.print();

	return 0;
}