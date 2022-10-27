#include <iostream>
#include <queue>
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


	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (cur->val > val) {
			cur->left = _insert(cur->left, val);
		} else if (cur->val < val) {
			cur->right = _insert(cur->right, val);
		}
		return cur;
	}

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

	int leftMost(Node* node) {
		if (!node->left) return node->val;
		return leftMost(node->left);
	}

	int rightMost(Node* node) {
		if (!node->right) return node->val;
		return rightMost(node->right);
	}

	Node* _remove(Node* node, int target) {
		if (!node) return nullptr;
		if (node->val == target) {
			if (!node->right && !node->left) {
				return nullptr;
			} else if (!node->right && node->left) {
				return node->left;
			} else if (node->right && !node->left) {
				return node->right;
			} else {
				node->val = rightMost(node->left);
				node->left = _remove(node->left, node->val);
			}
		} else if (node->val < target) {
			node->right = _remove(node->right, target);
			return node;
		} else {
			node->left = _remove(node->left, target);
			return node;
		}
		return node;
	}

public:
	Node* root;
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		root = _insert(root, val);
	}

	void inorder() {
		_inorder(root);
		cout << "\n";
	}
	void preorder() {
		_preorder(root);
		cout << "\n";
	}
	void postorder() {
		_postorder(root);
		cout << "\n";
	}

	int size(Node* node) {
		if (!node) return 0;
		return size(node->left) + size(node->right) + 1;
	}

	int height(Node* node) {
		if (!node) return 0;
		int left = height(node->left);
		int right = height(node->right);
		return max(left, right) + 1;
	}

	int minimalHeight(Node* node) {
		if (!node) return 0;
		int left = height(node->left);
		int right = height(node->right);
		return min(left, right) + 1;
	}

	void levelOrder(Node* node) {
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				Node* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				cout << cur->val << " ";
			}
			cout << '\n';
		}
	}

	Node* search(Node* node, int target) {
		if (!node) {
			return nullptr;
		}
		if (node->val == target) {
			return node;
		} else if (node->val < target) {
			return search(node->right, target);
		} else {
			return search(node->left, target);
		}
	}

	void remove(int target) {
		root = _remove(root, target);
	}

	int getWidth(Node* node) {
		queue<Node*> q;
		int ans = -1;
		q.push(root);
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
		return ans;
	}

	Node* LCA(Node* cur, Node* p, Node* q) {
		Node* lca;
		if (cur->val > min(p->val, q->val) && cur->val < max(p->val, q->val)) {
			lca = cur;
		} else if (cur->val > p->val && cur->val > q->val) {
			lca = LCA(cur->left, p, q);
		} else if (cur->val < p->val && cur->val < q->val) {
			lca = LCA(cur->right, p, q);
		}
		return lca;
	}
};

int main() {
	int n = 8;
	BST bst;
	int ar[n] = { 5, 2, 4, 1, 8, 6, 7, 10};
	for (int i = 0; i < n; i++) {
		bst.insert(ar[i]);
	}
	cout << bst.LCA(bst.root, bst.search(bst.root, 7), bst.search(bst.root, 10))->val;
	return 0;
}

/*
1. INSERT +
2. REMOVE + 
3. GETSIZE +
4. SEARCH +
5. TRAVERSALS (3) +++
6. GETHEIGHT +
7. GETWIDTH +
8. GETMINIMALHEIGHT +
9. GET lowestCommonAncestor +
10. LEVELORDER +

*/