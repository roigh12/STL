#include <iostream>
#include <algorithm>
#include <set>
#define M 50000


using namespace std;

int ms[M], temp[M], buff[M];

void merge(int* p, int len) {
	if (len < 2) return;
	int mid = len / 2;
	int i = 0, j = mid, k = 0;
	merge(p, mid);
	merge(p + mid, len - mid);
	while (i < mid && j < len)
		if (p[i] < p[j]) buff[k++] = p[i++];
		else buff[k++] = p[j++];
	while (i < mid) buff[k++] = p[i++];
	while (j < len) buff[k++] = p[j++];
	for (int i = 0; i < len; i++) p[i] = buff[i];
}

int main() {
	for (int i = 0; i < M; i++) {
		ms[i] = rand();
		temp[i] = ms[i];
	}
	sort(temp, temp + M);
	merge(ms, M);
	for (int i = 0; i < M; i++) {
		if (temp[i] != ms[i]) cout << "ASdf";
	}
	system("pause");
	return 0;
}