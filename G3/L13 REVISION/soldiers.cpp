#include <iostream>
#include <vector>
using namespace std;

struct SoldiersHeap {
	vector<pair<vector<int>, int> > ar;
	SoldiersHeap() {}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	bool comp(pair<vector<int>, int> p1, pair<vector<int>, int> p2) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < p1.first.size(); i++) {
			if (p1.first[i] == 1) {
				cnt1++;
			}
			if (p2.first[i] == 1) {
				cnt2++;
			}
		}
		if (cnt1 == cnt2) {
			return p1.second < p2.second;
		}
		return cnt1 < cnt2;
	}

	void insert(pair<vector<int>, int> val) {
		ar.push_back(val);
		int i = ar.size() - 1;
		while (i > 0 && comp(ar[i], ar[parent(i)])) {
			swap(ar[i], ar[parent(i)]);
			i = parent(i);
		}
	}

	int extract() {
		if (ar.empty()) {
			throw std::runtime_error("heap is empty");
		}
		if (ar.size() == 1) {
			int ret = ar[0].second;
			ar.pop_back();
			return ret;
		}
		int ret = ar[0].second;
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