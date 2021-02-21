#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>

typedef long long LL;
using namespace std;

const int MAXN = 2010;
char str[MAXN];


int main() {
	//#define FREOPEN
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) scanf(" %c", str + i);
	
	for (int b = 0, e = n - 1; b <= e;) {
		if (str[b] < str[e]) cout << str[b++];
		else if (str[b] > str[e]) cout << str[e--];
		else {
			int bb = b, ee = e;
			for (; bb < ee; bb++, ee--) {
				if (str[bb] < str[ee]) { cout << str[b++]; break; }
				if (str[bb] > str[ee]) { cout << str[e--]; break; }
			}
			if (!(bb < ee)) cout << str[b++];
		}
		ans++;
		if (ans % 80 == 0) putchar('\n');
	}
	

#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}