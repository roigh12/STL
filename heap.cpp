#include <iostream>
#include <algorithm>
#include <set>
#include "Windows.h"

using namespace std;

int heap[10000];
int heap_size;

void push(int data) {
	int target = heap_size + 1;
	while (target != 1 && heap[target / 2] < data) {
		heap[target] = heap[target / 2];
		target /= 2;
	}
	heap[target] = data;
	heap_size++;
}
void pop() {
	int parent = 1, child = 2;
	int temp = heap[heap_size];
	while (child < heap_size) {
		if (child + 1 < heap_size && heap[child + 1] > heap[child]) 
			child++;
		if (temp >= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	heap_size--;
}
bool comp(int a, int b) {
	return (a > b);
}

int main() {
	int a[10000];
	for (int i = 0; i < 9999; ++i) {
		a[i] = rand() % 12023;
		push(a[i]);
	}
	sort(a, a + 9999, comp);
	for (int i = 0; i < 9999; ++i) {
		if (a[i] != heap[1]) cout << "error" << endl;
		pop();
	}
	system("pause");
}