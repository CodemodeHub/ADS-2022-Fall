#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

	void _preorder(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

	void _postorder(Node* node) {
		if (!node) return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->val << " ";
	}

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	int _rightmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}

	int _leftmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->left) return cur->val;
		return _leftmost(cur->left);
	}

	Node* _remove(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return nullptr;
			} else if (cur->left && !cur->right) {
				Node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				Node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = _rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
				// cur->val = _leftmost(cur->right);
				// cur->right = _remove(cur->right, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}

	int _getSize(Node* node) {
		if (!node) return 0;
		return _getSize(node->left) + _getSize(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
	}

public:
	BST() {
		this->root = nullptr;
	}

	void inorder() {
		_inorder(root);
		cout << endl;
	}

	void preorder() {
		_preorder(root);
		cout << endl;
	}

	void postorder() {
		_postorder(root);
		cout << endl;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		// if (!root) root = newNode;
		if (root == nullptr) root = newNode;
	}

	void remove(int target) {
		root = _remove(root, target);
	}

	Node* search(int target) {
		return _search(root, target);
	}

	Node* getRoot() {
		return root;
	}

	int getSize() {
		return _getSize(root);
	}
};
void countTriangles(Node* node, vector<int>& v) {
	int lvl = 0;
	Node* left = node->left;
	Node* right = node->right;
	while (left && right) {
		v[lvl]++;
		left = left->left;
		right = right->right;
		lvl++;
	}
}

void dfs(Node* node, vector<int>& v) {
	if (!node) return;
	countTriangles(node, v);
	dfs(node->left, v);
	dfs(node->right, v);
}

void bfs(Node* root, vector<int>& v) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		countTriangles(cur, v);
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}


int main() {
	BST bst;
	int n, node;
	cin >> n;
	vector<int> v(n - 1);
	while (n--) {
		cin >> node;
		bst.insert(node);
	}
	dfs(bst.getRoot(), v);
	// bfs(bst.getRoot(), v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}


	return 0;
}