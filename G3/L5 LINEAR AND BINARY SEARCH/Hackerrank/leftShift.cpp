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

	void push_front(int val) {
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

	void push_back(int val) {
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

	bool empty() {
		return size == 0;
	}

	void print() {
		ListNode* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << '\n';
	}

	void shiftLeft(int k) {
		tail->next = head;
		while (k--) {
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr;
	}
};

int main() {
	int n, m, k;
	LinkedList ll;
	cin >> n >> k;
	while (n--) {
		cin >> m;
		ll.push_back(m);
	}
	ll.shiftLeft(k);
	ll.print();
	return 0;
}