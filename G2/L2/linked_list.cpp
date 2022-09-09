#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; // or type NUll instead of nullptr
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

	LinkedList() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addAtHead(int val) {
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr) {
			this->head = temp;
			this->tail = temp;
		} else {
			temp->next = this->head;
			this->head = temp;
		}
	}

	void addAtTail(int val) {
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		} else {
			this->tail->next = temp;
			this->tail = temp;
		}
	}

	void addAtIndex(int index, int val) {
		if (index > this->size) {
			return;
		} else if (index == 0) {
			this->addAtHead(val);
		} else if (index == this->size) {
			this->addAtTail(val);
		} else {
			ListNode *temp = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 1; i < index; i++) {
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp;
			this->size++;
		}
	}

};

int main()
{
	LinkedList* ll = new LinkedList();
	// cout << ll->size << endl;
	ll->addAtHead(10);
	ll->addAtHead(40);
	ll->addAtHead(80);

	ListNode *cur = ll->head;
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}

	return 0;
}