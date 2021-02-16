#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>

typedef long long LL;
using namespace std;

int stone[10010];

int main() {
//#define FREOPEN
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

	int N, Q;
	int times = 0;
	while ((cin >> N >> Q) && Q && N) {
		printf("CASE# %d:\n", ++times);
		int num = 0;
		for (int i = 0; i < N; i++) {
			cin >> stone[i];
		}
		sort(stone, stone + N);
		while (Q--) {
			cin >> num;
			bool ok = false;
			for (int i = 0; i < N; i++) {
				if (num == stone[i]) {
					printf("%d found at %d\n", num, i + 1);
					ok = true;
					break;
				}
			}
			if (!ok) printf("%d not found\n", num);
		}
	}
	

#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}