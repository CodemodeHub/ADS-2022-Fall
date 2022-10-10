#include<bits/stdc++.h>
using namespace std;
struct MinHeap {
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
        while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    } // O(logN)

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
        this->heapify(0);
        return root;
    }
    void heapify(int i) {
        int l = this->left(i);
        int r = this->right(i);
        int smallest = i;
        if (l < this->heap.size())
            smallest = min(this->heap[l], this->heap[i]);
        if (r < this->heap.size())
            smallest = min(this->heap[smallest], this->heap[r]);
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }
    bool empty() {
        return this->heap.size() == 0;
    }
};

vector<int> heapSort(int a[], int n) {
    MinHeap minHeap;
    for(int i = 0; i < n; i++)
        minHeap.insert(a[i]);
    vector<int> result_array;
    while(!minHeap.empty())
        result_array.push_back(minHeap.extactMin());
    return result_array;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<int> sorted_array = heapSort(a, n);
    for(int i = 0; i < n; i++)
        cout<<sorted_array[i]<<" ";
    cout<<endl;
    return 0;
}