#include <iostream>
#include <vector>
using namespace std;

struct MinHeap {
	vector<int> ar;
	MinHeap() {}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	void insert(int val) {
		ar.push_back(val);
		int i = ar.size() - 1;
		while (i > 0 && ar[i] > ar[parent(i)]) {
			swap(ar[i], ar[parent(i)]);
			i = parent(i);
		}
	}

	int extract() {
		if (ar.empty()) {
			throw std::runtime_error("heap is empty");
		}
		if (ar.size() == 1) {
			int ret = ar[0];
			ar.pop_back();
			return ret;
		}
		int ret = ar[0];
		ar[0] = ar.back(); // ar[ar.size() - 1]
		ar.pop_back();
		heapify(0);
		return ret;
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < ar.size() && ar[l] > ar[smallest]) {
			smallest = l;
		}
		if (r < ar.size() && ar[r] > ar[smallest]) {
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
	int n;
	MinHeap minh;
	cin >> n;
	while (n--) {
		minh.insert(n);
	}
	while (!minh.empty()) {
		cout << minh.extract() << " ";
	}
}