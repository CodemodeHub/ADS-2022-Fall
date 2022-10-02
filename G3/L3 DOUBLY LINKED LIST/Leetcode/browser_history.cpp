class Node
{
public:
	Node* prev, * next;
	string val;
	Node(string val) {
		this->val = val;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

class BrowserHistory
{
private:
	Node* cur;

public:
	BrowserHistory(string homepage) {
		this->cur = new Node(homepage);
	}

	void visit(string url) {
		Node* newPage = new Node(url);
		this->cur->next = newPage;
		newPage->prev = this->cur;
		this->cur = newPage;
		// this->cur = this->cur->next;
	}

	string back(int steps) {
		while (steps--) {
			if (this->cur->prev != nullptr) {
				this->cur = this->cur->prev;
			} else {
				break;
			}
		}
		return this->cur->val;
	}

	string forward(int steps) {
		// for (int i = 0; i < steps; i++)
		while (steps--) {
			if (this->cur->next != nullptr) {
				this->cur = this->cur->next;
			} else {
				break;
			}
		}
		return this->cur->val;
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */