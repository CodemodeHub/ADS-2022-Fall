#include <iostream>
#include <vector>
using namespace std;

struct SoldiersHeap {
	vector<pair<vector<int>, int> > ar;

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	bool comp(pair<vector<int>, int> v1, pair<vector<int>, int> v2) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < v1.first.size(); i++) {
			if (v1.first[i] == 1) {
				cnt1++;
			}
			if (v2.first[i] == 1) {
				cnt2++;
			}
		}
		if (cnt1 == cnt2) {
			return v1.second > v2.second;
		}
		return cnt1 > cnt2;
	}

	void insert(pair<vector<int>, int> v) {
		ar.push_back(v);
		int i = ar.size() - 1;
		while (i != 0 && comp(ar[i], ar[parent(i)])) {
			swap(ar[parent(i)], ar[i]);
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
		ar[0] = ar.back();
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

int main() {

	return 0;
}