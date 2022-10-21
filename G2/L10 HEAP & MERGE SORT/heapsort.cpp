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
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] > this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
};

int main() {
	MaxHeap heap;
	int ar[10] = { 4, 3, 9, 12, 54, 20, 65, 76, -2, 56 };
	int sortedAr[10];
	for (int i = 0; i < 10; i++) {
		heap.insert(ar[i]);
	}
	for (int i = 10 - 1; i >= 0; i--) {
		sortedAr[i] = heap.extractMax();
	}
	for (auto i : sortedAr) {
		cout << i << ' ';
	}
	return 0;
}


// 7 4
// insert 5
// insert 9
// insert 6
// print
// insert 10
// insert 20
// print

// 7 4
// insert 5 // 5
// insert 9 // 14
// insert 6 // 20
// print
// insert 10 // 30
// insert 20 // 50 - 5 == 45
// print