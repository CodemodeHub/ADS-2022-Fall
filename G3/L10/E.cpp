#include<bits/stdc++.h>
using namespace std;
struct MinHeap {
	vector<int> heap;
	int capacity;
	int sum;

	MinHeap(int capacity) {
		this->capacity = capacity;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}

	void checkAndInsert(int value) {
		if (heap.size() == capacity) {
			int oldBox = extractMin();
			if (oldBox < value) {
				insert(value);
				sum += value;
				sum -= oldBox;
			} else {
				insert(oldBox);
			}
		} else {
			insert(value);
			sum += value;
		}
	}
	
	void insert(int value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	int extractMin() {
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
		if (l < this->heap.size() && this->heap[l] < this->heap[biggest])
			biggest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[biggest])
			biggest = r;
		if (biggest != i) {
			swap(this->heap[i], this->heap[biggest]);
			this->heapify(biggest);
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	MinHeap mh(k);
	while (n--) {
		string command;
		cin >> command;
		if (command == "insert") {
			int x;
			cin >> x;
			mh.checkAndInsert(x);
		} else {
			cout << mh.sum << endl;
		}
	}

	return 0;
}