#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

template <class T1, class T2>
class _pair {
public:
	T1 first;
	T2 second;
	
	bool operator <(_pair<T1, T2> a) {
		if (first == a.first)
			return second < a.second;
		return first < a.first;
	}
};

_pair<int, string> p[30000];
pair<int, string> strp[30000];

int main() {
	for (int i = 0; i < 30000; ++i) {
		int temp = rand();
		string temp2 = to_string(rand());
		p[i] = { temp,temp2 };
		strp[i] = { temp,temp2 };
	}
	sort(p, p + 30000);
	sort(strp, strp + 30000);
	for (int i = 0; i < 30000; ++i) {
		if (p[i].first != strp[i].first || p[i].second != strp[i].second) {
			cout << "error\n";
		}
	}

	system("pause");
}
