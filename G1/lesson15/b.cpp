#include<bits/stdc++.h>
using namespace std;
struct MinHeap {
    vector<int> heap;
    MinHeap(int n) {
        this->heap.resize(n);
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
    void insert(int value) {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    int extactMin() {
        if (this->heap.size() == 0) return INT_MAX;
        if (this->heap.size() == 1) {
            int root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        int root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify_down(0);
        return root;
    }
    void update(int i, int x) {
        this->heap[i] += x;
        if(heap[i] < heap[parent(i)])
            heapify_up(i);
        else
            this->heapify_down(i);
    }
    void heapify_down(int i) {
        int l = this->left(i);
        int r = this->right(i);
        int smallest = i;
        if (l < this->heap.size() && this->heap[l] < this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify_down(smallest);
        }
    }
    void heapify_up(int i) {
        int p = this->parent(i);
        if(p > 0 && this->heap[p] > this->heap[i]) {
            swap(this->heap[p], this->heap[i]);
            this->heapify_up(p);
        }
    }
};

int main() {
    MinHeap* heap = new MinHeap(5);
    heap->insert(3);
    heap->insert(7);
    heap->insert(6);
    heap->insert(5);
    heap->insert(12);
    heap->insert(5);
    while (heap->heap.size() != 0) {
        cout << heap->extactMin() << " ";
    }
    return 0;
}