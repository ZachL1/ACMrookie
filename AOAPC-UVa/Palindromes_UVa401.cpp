#include<iostream>
#include<string>
using namespace std;

int main() {
	string a = "AEHIJLMOSTUVWXYZ12358";
	string b = "A3HILJMO2TUVWXY51SEZ8";
	char aa[400];
	for (int i = 0; i < a.length(); i++) {
		aa[a[i]] = b[i];
	}

	string str, hui, jin;
	while (getline(cin, str)) {
		hui = jin = str.substr();
		for (int i = 0; i < str.length(); i++) {
			hui[i] = str[str.length() - 1 - i];
			jin[i] = aa[str[str.length() - 1 - i]];
		}
		if (str.compare(hui) == 0) {
			if (str.compare(jin) == 0) cout << str + " -- is a mirrored palindrome.";
			else cout << str + " -- is a regular palindrome.";
		}
		else if (str.compare(jin) == 0) cout << str + " -- is a mirrored string.";
		else cout << str + " -- is not a palindrome.";
		cout << endl << endl;
	}
	return 0;
}