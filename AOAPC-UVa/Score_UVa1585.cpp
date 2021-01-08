#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		char c;
		int sum = 0, O_count = 0;
		while ((c = getchar()) != '\n') {
			if (c == 'O') {
				O_count++;
				sum += O_count;
			}
			if (c == 'X') O_count = 0;
		}
		printf("%d\n", sum);
	}

	return 0;

}