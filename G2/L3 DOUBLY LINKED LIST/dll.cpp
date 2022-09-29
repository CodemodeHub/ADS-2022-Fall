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
		this->next = nullptr; // or type NUll instead of nullptr
		this->prev = nullptr; // or type NUll instead of nullptr
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
		this->next = next;
		this->prev = prev;
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

	void addAtHead(int val)
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

	void addAtTail(int val)
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

	void addAtIndex(int index, int val)
	{
		if (index < 0 || index > this->size)
		{
			return;
		}
		else if (index == 0)
		{
			this->addAtHead(val);
		}
		else if (index == this->size)
		{
			this->addAtTail(val);
		}
		else
		{
			ListNode *temp = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next->prev = temp; // temp->next->prev = temp;
			cur->next = temp;
			temp->prev = cur;
			this->size++;
		}
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

	void deleteAtIndex(int index)
	{
		if (index == 0)
		{
			this->head = this->head->next;
			// delete (this->head->prev);
			this->head->prev = nullptr;
			this->size--;
		}
		else if (index == this->size - 1)
		{
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
			this->size--;
		}
		else if (index > 0 && index < this->size)
		{
			ListNode *cur = this->head;
			for (int i = 0; i < index; i++)
			{
				cur = cur->next;
			}
			ListNode *prevv = cur->prev;
			ListNode *nextt = cur->next;
			prevv->next = nextt;
			nextt->prev = prevv;
			this->size--;
		}
	}

	void print()
	{
		ListNode *cur = this->head;
		while (cur != nullptr)
		{
			cout << cur->val << "->";
			cur = cur->next;
		}
		cout << "nullptr" << endl;
	}

	void printReverse() {
		ListNode *cur = this->tail;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->prev;
		}
		cout << endl;
	}
};

ListNode *deleteDuplicates(ListNode *head)
{
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr)
		return head;
	ListNode *prev = head, *cur = head->next;
	while (cur != nullptr)
	{
		if (cur->val == prev->val)
		{
			prev->next = cur->next;
			cur = cur->next;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
	return head;
}

int main()
{
	DoublyLinkedList *dll = new DoublyLinkedList();
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		dll->addAtTail(m);
	}
	dll->head = deleteDuplicates(dll->head);
	dll->print();
	return 0;
}

// 7
// 2 3 3 11 11 44 55