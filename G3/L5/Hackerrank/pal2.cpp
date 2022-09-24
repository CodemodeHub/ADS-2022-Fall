#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
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
			this->tail = temp;
		}
	}

	bool empty()
	{
		return size == 0;
	}

	bool isPalindrome()
	{
		ListNode *slow = head, *fast = head, *prev, *temp;
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
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		return true;
	}
};

int main()
{
	int n, m;
	cin >> n;
	LinkedList ll;
	while (n--)
	{
		cin >> m;
		ll.push_back(m);
	}
	if (ll.isPalindrome())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}