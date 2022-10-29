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

Node* search(Node* node, int target) {
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		if (cur->value == target) return cur;
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
	return nullptr;
}

void bfs(Node* node, int& ans) {
	queue<Node*> q;
	q.push(node);
	while (!q.empty()) {
		int size = q.size();
		ans = max(ans, size);
		while (size--) {
			Node* cur = q.front();
			q.pop();
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
}

int main() {
	BinaryTree tree;
	int n;
	tree.insert(1);
	cin >> n;
	n--;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		Node* node = search(tree.root, x);
		if (z == 1) {
			node->right = new Node(y);
		} else {
			node->left = new Node(y);
		}
	}
	int ans = -1;
	bfs(tree.root, ans);
	cout << ans;


	return 0;
}