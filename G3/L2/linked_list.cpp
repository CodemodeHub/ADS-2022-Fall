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


struct LinkedList {
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void addAtHead(int val) {
		ListNode *newNode = new ListNode(val);
		if (this->size == 0) {
			this->head = newNode;
			this->tail = newNode;
		} else {
			newNode->next = this->head;
			this->head = newNode;
		}
		this->size++;
	}
};

int main()
{
	LinkedList *ll = new LinkedList();
	return 0;
}