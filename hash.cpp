#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <Windows.h>
#include <set>
#define NAME_SIZE 30000
using namespace std;

const int PN = 23;
const int HASH_SIZE = 10000;

int name_size = 0;
char name[NAME_SIZE][100];
int table[HASH_SIZE][30];

unsigned int get_key(char str[]) {
	unsigned int key = 0, p = 1;

	for (int i = 0; str[i] != 0; i++) {
		key += str[i] * p;
		p *= PN;
	}
	return key % HASH_SIZE;
}

bool strcmp(char a[], char b[]) {
	int i = 0;
	while (a[i]) {
		if (a[i] != b[i]) break;
		i++;
	}
	return a[i] - b[i];
}

int contain(char str[]) {
	unsigned int key = get_key(str);
	int size = table[key][0];
	for (int i = 1; i <= size; i++) {
		int n_pos = table[key][i];
		if (strcmp(str, name[n_pos]) == 0) {
			return n_pos;
		}
	}
	return -1;
}

void add(char str[]) {
	int len = 0;
	for (len = 0; str[len] != 0; len++) {
		name[name_size][len] = str[len];
	}
	name[name_size][len] = 0;

	unsigned int key = get_key(str);
	int& size = table[key][0];
	for (int i = 1; i <= size; ++i) {
		int n_pos = table[key][i];
		if (strcmp(name[n_pos], str) == 0) return;
	}
	table[key][++size] = name_size;
	++name_size;
}

bool remove(char str[]) {
	unsigned int key = get_key(str);
	int& size = table[key][0];
	for (int i = 1; i <= size; i++) {
		int n_pos = table[key][i];
		if (strcmp(str, name[n_pos]) == 0) {
			table[key][i] = table[key][size];
			--size;
			return true;
		}
	}
	return false;
}

void clear() {
	name_size = 0;
	for (int i = 0; i < HASH_SIZE; ++i) {
		table[i][0] = 0;
	}
}

int strlen(char *p) {
	char *ptr = p;
	while (*ptr != NULL) ptr++;
	return (ptr - p);
}

void reverse(char* a, char* b) {
	char c;
	for (char *i = a, *j = b; i < j; i++, j--) {
		c = *i;
		*i = *j;
		*j = c;
	}
}


int make_int(int min, int max) {
	return (rand() % (max - min)) + min;
}

char make_char() {
	int val = rand() % 52;
	if (val < 26) {
		return static_cast<char>('a' + val);
	}
	return static_cast<char>('A' + val - 26);
}


char input[NAME_SIZE][100];
int cmd[NAME_SIZE][2];
map<char*, int> stl_hash;

int my_find[NAME_SIZE], stl_find[NAME_SIZE];

const int REMOVE = 1;
const int FIND = 2;

int main() {
	for (int i = 0; i < NAME_SIZE; i++) {
		int len = make_int(10, 100);
		for (int j = 0; j < len; j++) {
			input[i][j] = make_char();
		}
		input[i][len] = 0;

		if (i > 1000) {
			cmd[i][0] = rand() % 3; //0 1 2
			cmd[i][1] = rand() % i;
		}
	}

	int my_hash_begin = GetTickCount();
	for (int i = 0; i < NAME_SIZE; i++) {
		if (contain(input[i]) == -1) {
			add(input[i]);
		}
		if (cmd[i][0] == REMOVE) {
			if (contain(input[cmd[i][1]]) != -1) {
				remove(input[cmd[i][1]]);
			}
		}
		if (cmd[i][0] == FIND) {
			my_find[i] = contain(input[cmd[i][1]]);
		}
	}
	int my_hash_end = GetTickCount();

	int stl_hash_begin = GetTickCount();
	for (int i = 0; i < NAME_SIZE; i++) {
		stl_hash[input[i]] = i;

		if (cmd[i][0] == REMOVE) {
			stl_hash.erase(input[cmd[i][1]]);
		}
		if (cmd[i][0] == FIND) {
			map<char*, int>::iterator iter = stl_hash.find(input[cmd[i][1]]);
			stl_find[i] = -1;
			if (iter != stl_hash.end()) {
				stl_find[i] = iter->second;
			}
		}
	}
	int stl_hash_end = GetTickCount();

	int my_hash_size = 0;
	for (int i = 0; i < HASH_SIZE; i++) {
		my_hash_size += table[i][0];
	}

	if (my_hash_size != stl_hash.size()) {
		cout << "hash size is not same !" << endl;
	}
	for (int i = 0; i < NAME_SIZE; i++) {
		if (my_find[i] != stl_find[i]) {
			cout << "hash find funtion is error !" << endl;
		}
	}

	cout << (my_hash_end - my_hash_begin) << endl;
	cout << (stl_hash_end - stl_hash_begin) << endl;

	int cnt = 0;
	int maxx = 0;
	for (int i = 0; i < HASH_SIZE; ++i) {
		if (table[i][0] == 0) cnt++;
		if (maxx < table[i][0]) maxx = table[i][0];
	}
	cout << cnt << endl;
	cout << maxx << endl;
}