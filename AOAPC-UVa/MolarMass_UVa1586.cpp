#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	map<char, double> g = { {'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01} };
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		double sum=0;
		/*char c;
		int n = 1;
		while ((c = getchar()) != '\n') {
			if (scanf("%d", &n)) {
				sum += g[c] * n;
			}
			else sum += g[c];
		}
		printf("%.3f\n", sum);*/


		int time = 1;
		string s;
		getline(cin, s);
		int l = s.length();
		for (int i = 0; i < l; i++) {
			bool is = true;
			double this_sum = 0;
			int j = i;
			while (i + 1 < l && isdigit(s[i + 1])) {
				this_sum = this_sum * time + g[s[j]] * (s[i + 1] - '0');
				time = 10;
				i++;
				is = false;
			}
			if (is) {
				this_sum += g[s[i]];
			}
			time = 1;
			sum += this_sum;
		}
		printf("%.3f\n", sum);
	}
	return 0;
}