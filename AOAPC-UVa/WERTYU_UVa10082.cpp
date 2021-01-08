#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main() {
	string a = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./ ";
	string b = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,. ";
	char aa[500];
	for (int i = 0; i < a.length(); i++) {
		aa[a[i]] = b[i];
	}
	string in;
	while (getline(cin, in)) {
		for (char i : in) putchar(aa[i]);
		cout << endl;
	}
	
	return 0;
}