#include <iostream>
#include <set>
using namespace std;

template <class T>

class _queue {
public:
	int ft, rear, sz;
	T* q;
	_queue() {
		ft = rear = sz = 0;
		q = new T[100];
	} 
	void clear() {
		ft = rear = sz = 0;
	}
	bool empty() {
		return (sz == 0);
	}
	T front() {
		return q[ft];
	}
	void push(T val) {
		q[rear] = val;
		rear = ++rear % 100;
		sz++;
	}
	T pop() {
		T val = q[ft];
		ft = ++ft % 100;
		sz--;
		return val;
	}
};


int main() {
	_queue<int> q;
	for (int i = 0; i < 10; ++i) {
		q.push(i);
	}
	while (!q.empty()) {
		cout << q.front() << ' ';

		cout << q.pop() << endl;
	}
	q.clear();
	for (int i = 0; i < 5; ++i) {
		q.push(i);
	}
	while (!q.empty()) {
		cout << q.pop() << endl;
	}
	system("pause");
}