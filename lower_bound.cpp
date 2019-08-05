#include <iostream>
#include <set>
using namespace std;
int lower_bound(int* arr, int n, int key) {
	int left = 0;
	int right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < key) left = mid + 1;
		else right = mid;
	}

	return right;
}

int upper_bound(int* arr, int n, int key) {
	int left = 0;
	int right = n;
	
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] <= key) left = mid + 1;
		else right = mid;
	}

	return right;
}

int main() {
	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
	cout << "lower_bound(6) : " << lower_bound(arr, 10, 6) << endl;
	cout << "lower_bound(7) : " << lower_bound(arr, 10, 7) << endl;
	cout << "lower_bound(8) : " << lower_bound(arr, 10, 8) << endl;
	cout << "lower_bound(9) : " << lower_bound(arr, 10, 9) << endl;

	cout << endl;

	cout << "upper_bound(6) : " << upper_bound(arr, 10, 6) << endl;
	cout << "upper_bound(7) : " << upper_bound(arr, 10, 7) << endl;
	cout << "upper_bound(8) : " << upper_bound(arr, 10, 8) << endl;
	cout << "upper_bound(9) : " << upper_bound(arr, 10, 9) << endl;

}