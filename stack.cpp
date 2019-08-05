#include <iostream>
#include <set>
using namespace std;

template <class T>

class _stack {
public:
	int top;
	T* st;
	_stack() {
		top = -1;
		st = new T[100];
	} 
	void clear() {
		top = -1;
	}
	bool empty() {
		return (top == -1);
	}
	int size() {
		return top+1;
	}
	void push(int val) {
		st[++top] = val;
	}
	T pop() {
		return st[top--];
	}
	T& operator [](int idx) {
		return st[idx];
	}
};

int main() {
	_stack<int> s;
	for (int i = 0; i <= 10; ++i) {
		s.push(i);
	}
	while (!s.empty()) {
		cout << s.top << ' ';
		cout << s.pop() << endl;
	}
	system("pause");
}