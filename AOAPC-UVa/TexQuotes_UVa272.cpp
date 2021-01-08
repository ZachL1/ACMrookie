#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	char ch;
	bool is = true;
	while (scanf("%c", &ch) != EOF) {
		if (ch != '\"') putchar(ch);
		else {
			if (is) {
				printf("``");
				is = false;
			}
			else {
				printf("''");
				is = true;
			}
		}
	}

	return 0;
}