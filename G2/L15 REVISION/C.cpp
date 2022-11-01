#include<bits/stdc++.h>
using namespace std;
struct MaxHeap {
	vector<int> heap;

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(int value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	int extract() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			int root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		int root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int biggest = i;
		if (l < this->heap.size() && this->heap[l] > this->heap[biggest])
			biggest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[biggest])
			biggest = r;
		if (biggest != i) {
			swap(this->heap[i], this->heap[biggest]);
			this->heapify(biggest);
		}
	}

	void change(int index, int value) {
		this->heap[index - 1] += value;
		int i = index - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
		cout << i + 1 << endl;
	}

	void print() {
		for (int i = 0; i < this->heap.size(); i++) {
			cout << this->heap[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	MaxHeap h;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		h.insert(x);
	}
	int q;
	cin >> q;
	while (q--) {
		int index, value;
		cin >> index >> value;
		h.change(index, value);
	}
	h.print();
	return 0;
}

// 6
// 12 6 8 3 4 7
// 2
// 5 11
// 3 6