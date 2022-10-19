#include<bits/stdc++.h>
using namespace std;
struct Task {
	string task_name;
	double days_left;
	int points;
	int time;
	Task(string task_name, double days_left, int points, int time) {
		this->task_name = task_name;
		this->days_left = days_left;
		this->points = points;
		this->time = time;
	}
};
struct TaskHeap {
	vector<Task*> heap;
	int size;
	TaskHeap() {
		size = 0;
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
	void swap(int i, int j) {
		Task* temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
	bool compare(Task* task1, Task* task2) {
		if (task1->time == task2->time) {
			if (task1->points == task2->points) {
				if (task1->days_left == task2->days_left) {
					return task1->task_name > task2->task_name;
				}
				return task1->days_left > task2->days_left;
			}
			return task1->points < task2->points;
		}
		return task1->time > task2->time;
	}
	void insert(Task* task) {
		heap.push_back(task);
		size++;
		int i = size - 1;
		while (i != 0 && compare(heap[parent(i)], heap[i])) {
			swap(i, parent(i));
			i = parent(i);
		}
	}
	Task* extract() {
		if (size == 0) {
			return nullptr;
		}
		if (size == 1) {
			size--;
			Task* root = heap[0];
			heap.pop_back();
			return root;
		}
		Task* root = heap[0];
		heap[0] = heap[size - 1];
		size--;
		heap.pop_back();
		if (root->days_left > 0 && root->time <= root->days_left * 0.1) {
			for (int i = 0; i < heap.size(); i++) {
				heap[i]->days_left -= root->time * 0.1;
			}
		}
		heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < size && compare(heap[i], heap[l])) {
			largest = l;
		}
		if (r < size && compare(heap[largest], heap[r])) {
			largest = r;
		}
		if (largest != i) {
			swap(i, largest);
			heapify(largest);
		}
	}
};
int main() {
	int n;
	cin >> n;
	TaskHeap taskHeap;
	while (n--) {
		string operation;
		cin >> operation;
		if (operation == "insert") {
			string task_name;
			double days_left;
			int points, time;
			cin >> task_name >> days_left >> points >> time;
			taskHeap.insert(new Task(task_name, days_left, points, time));
		} else {
			Task* task = taskHeap.extract();
			if (!task) {
				cout << "No tasks!\n";
			} else if (task->days_left <= 0) {
				cout << "Deadline passed!\n";
			} else if (task->days_left * 10 < task->time) {
				cout << "Task " << task->task_name << " is not possible to complete!\n";
			} else {
				cout << task->task_name << " completed!" << endl;
			}
		}
	}
}