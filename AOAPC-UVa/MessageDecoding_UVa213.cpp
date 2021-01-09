#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char code[8][500];

char readchar() {
	char c;
	while ((c = getchar()) == '\n')
		continue;
	return c;
}
int readint(int n) {
	int v=0;
	while (n--) {
		char c = readchar();
		v = v * 2 + c - '0';
	}
	return v;
}
bool readcode() {
	memset(code, 0, sizeof(code));
	int len = 1, v = 0;
	for(len=1; len<8; ++len)
		for (v = 0; v < (1 << len) - 1; v++) {
			char c = getchar();
			if (c == EOF) return false;
			if (c == '\n') return true;
			code[len][v] = c;
		}
	return true;
}


int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	while (readcode()) {
		while (true) {
			int len = readint(3);
			if (len == 0)
				break;
			while (true) {
				int v = readint(len);
				if (v == (1 << len) - 1)
					break;
				printf("%c", code[len][v]);
			}
		}
		getchar();
		std::cout << std::endl;
	}
	return 0;
}