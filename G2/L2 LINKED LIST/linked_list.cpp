#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

struct LinkedList
{
	int size;
	ListNode* head;
	ListNode* tail;

	LinkedList() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	ListNode* findTail() {
		ListNode* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		return cur;
	}

	void addAtHead(int val) {
		this->size++;
		ListNode* temp = new ListNode(val);
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
		ListNode* temp = new ListNode(val);
		if (this->head == nullptr) {
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
			ListNode* temp = new ListNode(val);
			ListNode* cur = this->head;
			for (int i = 1; i < index; i++) {
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp;
			this->size++;
		}
	}

	int get(int index) {
		if (index < 0 || index >= this->size) {
			return -1;
		}
		ListNode* cur = this->head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}
		return cur->val;
	}

	void deleteAtIndex(int index) {
		if (index == 0) {
			this->head = this->head->next;
			this->size--;
		} else if (index == this->size - 1) {
			ListNode* cur = this->head;
			while (cur->next != this->tail) {
				cur = cur->next;
			}
			this->tail = cur;
			this->size--;
		} else if (index > 0 && index < this->size) {
			ListNode* cur = this->head;
			for (int i = 0; i < index - 1; i++) {
				cur = cur->next;
			}
			ListNode* toDel = cur->next;
			cur->next = cur->next->next;
			this->size--;
			delete (toDel);
		}
	}

	void printLL() {
		ListNode* cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
		// while (cur->next) {

		// }
	}
};

int main() {
	LinkedList* ll = new LinkedList();
	LinkedList* ll2 = new LinkedList();
	// cout << ll->size << endl;
	ll->addAtHead(10);
	ll->addAtTail(200);
	ll->addAtHead(40);
	ll->addAtHead(80);
	ll->addAtIndex(2, 1337);
	ll2->head = ll->tail;
	ll2->tail = ll->tail;
	ll->size = 1;
	ll2->addAtTail(500);
	ll2->addAtTail(500);
	ll2->addAtTail(500);
	ll->printLL();
	ll2->printLL();

	return 0;
}