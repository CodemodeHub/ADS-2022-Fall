#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

struct LL {
	Node* head;

	LL() {
		this->head = nullptr;
	}

	bool empty() {
		return head == nullptr;
	}

	Node* getTail() {
		Node* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		return cur;
	}

	void push_back(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
		} else {
			Node* tail = getTail();
			tail->next = newNode;
		}
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

	int size() {
		int cnt = 0;
		Node* cur = head;
		while (cur) {
			cnt++;
			cur = cur->next;
		}
		return cnt;
	}

	void insert(int val, int pos) {
		Node* newNode = new Node(val);
		if (pos == 1) {
			push_front(val);
		} else if (pos - 1 == size()) {
			push_back(val);
		} else {
			Node* cur = head;
			while (--pos > 1) {
				cur = cur->next;
			}
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}

	void print() {
		Node* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << "\n";
	}

	Node* pop_back() {
		if (!head->next) {
			Node* node = head;
			head = nullptr;
			return node;
		}
		Node* cur = head;
		while (cur->next->next) {
			cur = cur->next;
		}
		Node* node = cur->next;
		cur->next = nullptr;
		return node;
	}

	Node* pop_front() {
		Node* node = head;
		head = head->next;
		return node;
	}

	Node* remove(int pos) {
		if (pos == 1) {
			return pop_front();
		}
		if (pos == size()) {
			return pop_back();
		}
		Node* cur = head;
		while (--pos > 1) {
			cur = cur->next;
		}
		Node* node = cur->next;
		cur->next = cur->next->next;
		return node;
	}

	void reverse() {
		Node* prev = nullptr, * cur = head, * next;
		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}

	Node* search(int val) {
		Node* cur = head;
		while (cur) {
			if (cur->val == val) {
				return cur;
			}
			cur = cur->next;
		}
		return nullptr;
	}

	void shiftLeft(int k) {
		k %= size();
		Node* tail = getTail();
		tail->next = head;
		while (k--) {
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr;
	}

	void shiftRight(int k) {
		k %= size();
		shiftLeft(size() - k);
	}

	void replace(int pos1, int pos2) {
		Node* node = remove(pos1);
		insert(node->val, pos2);
	}

	void swap(int pos1, int pos2) {
		replace(pos1, pos2);
		replace(pos2 - 1, pos1);
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	LL ll;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		ll.push_back(x);
	}
	ll.print();
	ll.swap(2, 3);
	ll.print();
}

/*
1. Insert at random pos +
2. push back +
3. push front +
4. pop back +
5. pop front +
6. empty() +
7. reverse +
8. sort*
9. remove at random pos +
10. search for val + 
11. replace +
12. swap +
13. shift left + 
14. shift right + 
*/