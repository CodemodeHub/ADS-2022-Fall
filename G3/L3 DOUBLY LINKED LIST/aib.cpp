#include <iostream>

using namespace std;

struct Node
{
	string s;
	Node* next;

	Node(string s) {
		this->s = s;
		next = nullptr;
	}
};
struct LinkedList
{
	Node* head;
	Node* tail;
	int size;
	int index;

	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
		index = 0;
	}

	void push(string s) {
		Node* newNode = new Node(s);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}

	void print() {
		Node* cur = head;

		while (cur != nullptr) {
			cout << cur->s << " ";
			cur = cur->next;
		}
	}

	void change(int k) {
		Node* cur = this->head;
		cout << head->s;
		while (k--) {
			this->head = this->head->next;
			cur->next = nullptr;
			this->tail->next = cur;
			this->tail = cur;
		}
	}
};

int main() {
	LinkedList list;
	int n, k;
	cin >> n >> k;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		list.push(s);
	}

	list.change(k);
	// list.print();
}
// 5
// 2
// the show must go on