#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int val) {
		this->next = nullptr;
		this->val = val;
	}
};

struct LL {
	Node* head;

	LL() {
		this->head = nullptr;
	}

	Node* getTail() {
		Node* node = head;
		while (node->next) {
			node = node->next;
		}
		return node;
	}

	void push_front(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
		} else {
			newNode->next = head;
			head = newNode;
		}
	}

	void push_back(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
		} else {
			Node* node = getTail();
			node->next = newNode;
		}
	}

	void insert(int val, int pos) {
		if (pos == 1) {
			push_front(val);
			return;
		}
		Node* cur = head;
		Node* newNode = new Node(val);
		while (--pos > 1) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}

	Node* pop_front() {
		if (!head->next) {
			Node* ret = head;
			head = nullptr;
			return ret;
		}
		Node* node = head;
		head = head->next;
		return node;
	}

	Node* pop_back() {
		if (!head->next) {
			Node* ret = head;
			head = nullptr;
			return ret;
		}
		Node* cur = head;
		while (cur->next->next) {
			cur = cur->next;
		}
		Node* tail = cur->next;
		cur->next = nullptr;
		return tail;
	}

	Node* remove(int pos) {
		if (pos == 1) {
			return pop_front();
		}
		Node* cur = head;
		while (--pos > 1) {
			cur = cur->next;
		}
		if (!cur->next) {
			return pop_back();
		}
		Node* res = cur->next;
		cur->next = cur->next->next;
		return res;
	}

	void print() {
		if (!head) {
			cout << "PUSTO!\n";
			return;
		}
		Node* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << "\n";
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void shiftLeft(int k) {
		Node* tail = getTail();
		tail->next = head;
		while (k--) {
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr;
	}

	int getSize() {
		Node* cur = head;
		int cnt = 0;
		while (cur) {
			cur = cur->next;
			cnt++;
		}
		return cnt;
	}

	void shiftRight(int k) {
		shiftLeft(getSize() - k);
	}

	void reverse() {
		Node* prev = nullptr;
		Node* cur = head;
		Node* next;
		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}

	void replace(int pos1, int pos2) {
		Node* node = remove(pos1);
		insert(node->val, pos2);
	}

	void swap(int pos1, int pos2) {
		replace(pos1, pos2);
		replace(pos2 - 1, pos1);
	}

	Node* middleNode() {
		Node* slow = head, * fast = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	LL ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ll.push_back(x);
	}
	ll.print();
	cout << ll.middleNode()->val << endl;
	ll.print();
}