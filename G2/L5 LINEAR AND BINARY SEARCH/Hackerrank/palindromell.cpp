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

	bool isPalindrome() {
		ListNode* slow = head, * fast = head, * prev, * temp;
		while (fast && fast->next)
			slow = slow->next, fast = fast->next->next;
		prev = slow, slow = slow->next, prev->next = NULL;
		while (slow)
			temp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = temp;
		fast = head;
		slow = prev;
		while (slow)
			if (fast->val != slow->val)
				return false;
			else {
				fast = fast->next;
				slow = slow->next;
			}
		return true;
	}
};

int main() {
	int n, m;
	cin >> n;
	LinkedList ll1;
	while (n--) {
		cin >> m;
		ll1.push_back(m);
	}
	LinkedList ll2 = ll1;
	ll2.reverse();
	ListNode* cur1 = ll1.head;
	ListNode* cur2 = ll2.head;
	while (cur1 != nullptr && cur2 != nullptr) {
		if (cur1->val != cur2->val) {
			cout << "NO";
			return;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	cout << "YES";
	return 0;
}