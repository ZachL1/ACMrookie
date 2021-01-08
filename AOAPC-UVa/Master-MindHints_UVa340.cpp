#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, times=0;
	int a[10], b[10];
	while (scanf("%d", &n) && n) {
		memset(a, 0, sizeof(a));
		int* ex = new int[n];
		int* an = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", ex + i);
			a[ex[i]]++;
		}
		printf("Game %d:\n", ++times);

		bool is;
		do {
			memcpy(b, a, sizeof(int) * 10);
			int aa = 0, bb = 0;
			is = false;
			for (int i = 0; i < n; i++) {
				scanf("%d", an + i);
				if (an[i] == ex[i]) {
					aa++;
					b[an[i]]--;
				}
				if (an[i]) is = true;
			}
			if (!is) break;

			for (int i = 0; i < n; i++) {
				if ((an[i] != ex[i]) && b[an[i]]) {
					bb++;
					b[an[i]]--;
				}
			}

			printf("    (%d,%d)\n", aa, bb);

		} while (is);

	}

	return 0;
}