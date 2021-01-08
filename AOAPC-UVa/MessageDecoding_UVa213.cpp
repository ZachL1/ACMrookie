#include <iostream>
#include <unordered_map>
#include <cmath>
#include <string>
using namespace std;

string to2str(int w, int n) {
	string s = to_string(n % 2);
	n /= 2;
	while (n) {
		s = to_string(n % 2) + s;
		n /= 2;
	}
	while (s.length() < w) {
		s = "0" + s;
	}
	return s;
}

int main() {
	string temp;
	unordered_map<string, char> m;
	char c;
	while (scanf("%c", &c)!=EOF) {
		if (c == '\n')continue;
		int w = 1;
		int count = -1;
		m.clear();

		do {
			++count;
			temp = to2str(w, count);
			m.insert(make_pair(temp, c));

			if (count == (int)exp2(w) - 2) {
				count = -1;
				++w;
			}
		} while (scanf("%c", &c) && c != '\n');
		
		w = 0;
		for (int i = 2; i >= 0; --i) {
			scanf("%c", c);
			if (c - '0') w += (int)exp2(i);
		}
		
		while (scanf("%c", c)) {
			if (c == '\n') continue;
			temp.clear();
			temp += c;
			for(int i=1; i<w)
		}

	}
}