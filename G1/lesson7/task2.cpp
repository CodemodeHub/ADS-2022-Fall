#include<bits/stdc++.h>
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
				// cur->val = _rightmost(cur->left);
				// cur->left = _remove(cur->left, cur->val);
				cur->val = _leftmost(cur->right);
				cur->right = _remove(cur->right, cur->val);
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
	Node* root;
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

	void getSize() {
		cout << _getSize(root) << endl;
	}

    vector<Node* > getLeafes() {
        vector<Node*> leafes;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (!cur->left && !cur->right) {
                leafes.push_back(cur);
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return leafes;
    }
};

int main() {
    int n, k;
    cin>>n>>k;
    BST bst;
    vector<string> p;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        bst.insert(x);
    }
    for(int i = 0; i< k; i++){
        string s;
        cin>>s;
        p.push_back(s);
    }
    for(int i = 0; i < p.size(); i++) {
        string path = p[i];
        Node* cur = bst.root;
        bool isExist = true;
        for(int j = 0; j < path.size(); j++) {
            char direction = path[j];
            if(direction == 'L')
                cur = cur->left;
            else if(direction == 'R')
                cur = cur->right;
            if(!cur) {
                isExist = false;
                break;
            }
        }
        if(isExist)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}