#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	char s[90];
	scanf("%d", &T);
	while (T--) {
		getchar();
		scanf("%s", s);
		int len = strlen(s);
		_rep(q, 1, len) {
			bool ans = true;
			if (len % q) continue;
			_for(i, 0, q) {
				for (int j = i; j < len; j += q) {
					if (s[j] != s[i]) {
						ans = false;
						break;
					}
				}
				if (!ans) break;
			}
			if (ans) {
				printf("%d\n", q);
				if (T != 0) putchar('\n');
				break;
			}
		}

	}
	return 0;
}