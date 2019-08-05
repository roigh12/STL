#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <class T>


class _vector {

public:
	int sz;
	int capacity;
	T* vc;
	_vector() {
		sz = 0;
		capacity = 32;
		vc = new T[capacity];
	}
	_vector(int k) {
		sz = k;
		capacity = k;
		vc = new T[capacity];
	}
	~_vector() {
		delete[] vc;
	}
	void clear() {
		sz = 0;
		capacity = 32;
		delete[] vc;
		vc = new T[capacity];
	}
	int size() {
		return sz;
	}
	bool empty() {
		return !sz;
	}
	T* begin() {
		return &vc[0];
	}
	T* end() {
		return &vc[0] + sz;
	}

	void push_back(T val) {
		if (sz == capacity) {
			int k = 2 * sz;
			T* tmp = new T[k];
			for (int i = 0; i < sz; i++)
				tmp[i] = vc[i];
			delete[] vc;
			vc = tmp;
			capacity = k;
		}
		vc[sz++] = val;
	}
	void pop_back() {
		sz--;
	}
	T& operator [](int i) {
		return vc[i];
	}
};

int main() {
	int T = 2;
	while (T--) {
		_vector<int> vc;
		cout << vc.size() << endl;
		for (int i = 0; i < 10; ++i) {
			int temp = rand();
			vc.push_back(temp);
		}
		sort(vc.begin(), vc.end());

		for (int i = 0; i < 10; ++i) {
			cout << vc[i] << '\n';
		} 

	}
	return 0;
}

