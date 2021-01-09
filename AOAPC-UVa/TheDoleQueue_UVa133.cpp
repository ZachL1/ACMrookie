#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include<vector>
using namespace std;
int n;
int a[20];
int go(int begin, int d, int m) {
	while (m--) {
		do {
			begin = (begin + d + n - 1) % n + 1;
		} while (a[begin]);
	}
	return begin;
}
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	int k, m;
	bool first = true;
	while (scanf("%d%d%d", &n, &k, &m) && n && k && m) {
		/*if (first) first = false;
		if (!first) cout << endl;*/
		memset(a, 0, sizeof(a));
		/*for (int i = 1; i <= n; i++)
			a[i] = i;*/
		int A = n, B = 1;
		int left = n;
		while (left) {
			A = go(A, 1, k);
			B = go(B, -1, m);
			printf("%3d", A);
			a[A] = 1;
			--left;
			if (B != A) {
				printf("%3d", B);
				a[B] = 1;
				--left;
			}
			printf("%c", left ? ',' : '\n');
		}
	}
	return 0;
}