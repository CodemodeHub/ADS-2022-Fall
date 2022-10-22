#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct DotsHeap {
	vector<pair<int, int> > ar;
	DotsHeap() {}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	bool comp(pair<int, int> p1, pair<int, int> p2) {
		int h1 = pow(p1.first, 2) + pow(p1.second, 2);
		int h2 = pow(p2.first, 2) + pow(p2.second, 2);
		return h1 < h2;
	}

	void insert(pair<int, int> val) {
		ar.push_back(val);
		int i = ar.size() - 1;
		while (i > 0 && comp(ar[i], ar[parent(i)])) {
			swap(ar[i], ar[parent(i)]);
			i = parent(i);
		}
	}

	pair<int, int> extract() {
		if (ar.empty()) {
			throw std::runtime_error("heap is empty");
		}
		if (ar.size() == 1) {
			pair<int, int> ret = ar[0];
			ar.pop_back();
			return ret;
		}
		pair<int, int> ret = ar[0];
		ar[0] = ar.back(); // ar[ar.size() - 1]
		ar.pop_back();
		heapify(0);
		return ret;
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < ar.size() && comp(ar[l], ar[smallest])) {
			smallest = l;
		}
		if (r < ar.size() && comp(ar[r], ar[smallest])) {
			smallest = r;
		}
		if (smallest != i) {
			swap(ar[i], ar[smallest]);
			heapify(smallest);
		}
	}

	bool empty() {
		return ar.empty();
	}
};