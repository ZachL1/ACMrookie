#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int i = n - to_string(n).length() * 9;
		for (; i < n; i++) {
			string i_str = to_string(i);
			int i_n = i;
			for (char j : i_str)
				i_n += j - '0';
			if (i_n == n) break;
		}
		printf("%d\n", i == n ? 0 : i);
	}
	return 0;
}