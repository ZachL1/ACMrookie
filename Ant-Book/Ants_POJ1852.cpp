#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
using namespace std;
typedef long long int;
int a[1000010];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int l, num;
		int min= LLONG_MAX, max= LLONG_MAX;
		scanf("%d%d", &l, &num);
		int temp;
		for (int i = 1; i <= num; i++) {
			cin >> temp;

			if (temp > max) max = temp;
			if (l - temp > max) max = l - temp;

			int mmin = temp < l - temp ? temp : l - temp;
			if (mmin > min) min = mmin;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}