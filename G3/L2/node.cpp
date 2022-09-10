#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() {
		this->val = 0;
		this->next = nullptr; // NULL, if this doesnt work
	}

	ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}

	ListNode(int val, ListNode *next) {
		this->val = val;
		this->next = next;
	}
};

int main()
{
	ListNode *myNode1 = new ListNode();
	ListNode *myNode2 = new ListNode(5, myNode1);
	cout << myNode1->val;
	return 0;
}