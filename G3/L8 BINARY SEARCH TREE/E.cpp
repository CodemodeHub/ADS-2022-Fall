#include<bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node* left, * right;
	Node(int value) {
		this->value = value;
		left = right = nullptr;
	}
};

struct BinaryTree {
	Node* root;
	BinaryTree() {
		root = nullptr;
	}

	BinaryTree(Node *root) {
		this->root = root;
	}
private:
	void inorder(Node* node) {
		if (!node) return;
		this->inorder(node->left);
		cout << node->value << " ";
		this->inorder(node->right);
	}
	
	void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}
	
	void postorder(Node* node) {
		if (!node) return;
		this->postorder(node->left);
		this->postorder(node->right);
		cout << node->value << " ";
	}

	Node* findBlankNode() {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left && q.front()->right) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		return q.front();
	}
public:
	void inorder() {
		this->inorder(this->root);
	}
	
	void preorder() {
		this->preorder(this->root);
	}
	
	void postorder() {
		this->postorder(this->root);
	}
	
	void insert(int value) {
		if (!this->root) {
			this->root = new Node(value);
		} else {
			Node* cur = this->findBlankNode();
			if (!cur->left)
				cur->left = new Node(value);
			else if (!cur->right)
				cur->right = new Node(value);
		}
	}

	Node* search(Node *node, int value) {
		if (node == nullptr) 
			return node;
		if (node->value == value) {
			return node;
		} else {
			Node* foundNode = search(node->left, value);
			if (foundNode != nullptr) {
				return foundNode;
			} else {
				return search(node->right, value);
			}
		}
		return node;
	}

	void remove(int value) {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left->value != value && q.front()->right->value != value) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		Node* cur = q.front();
		if (cur->left->value == value)
			cur->left = nullptr;
		else
			cur->right = nullptr;
	}
};

int h;

void dfs(Node* cur, int lvl) {
	if (cur == nullptr) {
		return;
	}
	h = max(h, lvl);
	dfs(cur->left, lvl + 1);
	dfs(cur->right, lvl + 1);
}

void dfs2(Node* cur, int lvl, vector<int> &w) {
	w[lvl - 1]++;
	if (cur == nullptr) {
		return;
	}
	dfs2(cur->left, lvl + 1, w);
	dfs2(cur->right, lvl + 1, w);
}

int main() {
	BinaryTree bt(new Node(1));
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Node* parent = bt.search(bt.root, x);
		if (z == 0) {
			parent->left = new Node(y);
		} else {
			parent->right = new Node(y);
		}
	}
	dfs(bt.root, 1);
	vector<int> w(h);
	dfs2(bt.root, 1, w);
	sort(w.begin(), w.end());
	cout << w[w.size() - 1];

	return 0;
}
