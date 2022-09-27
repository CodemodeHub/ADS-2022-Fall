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

int main()
{

	ListNode *node1 = new ListNode(10);
	ListNode *node2 = new ListNode(20, node1);
	cout << node1->val << endl;
	cout << node2->val << " " << node2->next->val << endl;

	return 0;
}