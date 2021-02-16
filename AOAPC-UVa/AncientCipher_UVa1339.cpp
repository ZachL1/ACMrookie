#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
typedef long long LL;
using namespace std;

int cnt1[27], cnt2[27];

int main() {
	//freopen("input.txt","r", stdin);
	//freopen("output.txt", "w", stdout);

	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (char i : s1) {
			cnt1[i - 'A']++;
		}
		for (char i : s2) {
			cnt2[i - 'A']++;
		}
		sort(begin(cnt1),end(cnt1));
		sort(begin(cnt2),end(cnt2));
		int i = 0;
		for (; i < 26; i++) {
			if (cnt1[i] != cnt2[i])
				break;
		}
		if (i == 26)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	
	return 0;
}