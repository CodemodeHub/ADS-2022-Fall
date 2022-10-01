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
	int extractMax() {
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
};

int main() {
	MaxHeap mh;
	mh.insert(23);
	mh.insert(45);
	mh.insert(132);
	mh.insert(44);
	mh.insert(12);
	mh.insert(65);
	mh.insert(-34);
	mh.insert(8);
	while (mh.heap.size() > 0) {
		cout << mh.extractMax() << " ";
	}

	return 0;
}