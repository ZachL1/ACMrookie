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

	int ans[10];
	int T;
	scanf("%d\n", &T);
	while (T--) {
		memset(ans, 0, sizeof(ans));
		int num;
		scanf("%d", &num);
		_rep(i, 1, num) {
			for (char j : to_string(i)) {
				ans[j - '0']++;
			}
		}
		_for(i, 0, 10) {
			printf("%d%c", ans[i], (i==9)?'\n':' ');
		}
	}

	return 0;
}