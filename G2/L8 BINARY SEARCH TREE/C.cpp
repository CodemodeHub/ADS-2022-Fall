#include<iostream>
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
		if (!root) root = newNode;
	}

	void remove(int target) {
		_remove(root, target);
	}

	Node* search(int target) {
		return _search(root, target);
	}

	int getSize() {
		return _getSize(root);
	}

	void solve(int target) {
		Node* targetNode = search(target);
		_preorder(targetNode);
	}
};

int main() {
	BST bst;
	int n, node, target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node;
		bst.insert(node);
	}
	cin >> target;
	bst.solve(target);

	return 0;
}