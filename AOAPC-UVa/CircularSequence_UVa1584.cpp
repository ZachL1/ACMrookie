#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	int tt;
	scanf("%d", &tt);
	getchar();
	while (tt--) {
		string s, mins, temp;
		getline(cin, s);
		mins = temp = s;
		int l = s.length();
		for (int i = 1; i < l; i++){
			for (int j = i, count = 0; count < l; count++, j = (j + 1) % l) {
				//cout << j << endl;
				temp[count] = s[j];
			}
			if (temp < mins) mins = temp.substr();
		}

		cout << mins << endl;
	}
	return 0;
}