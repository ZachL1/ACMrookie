// UVa101 The Blocks Problem
// Rujia Liu
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn]; // 每个pile[i]是一个vector

void find_block(int a, int& p, int& h) {
	for (p = 0; p < n; p++) {
		for (h = 0; h < pile[p].size(); h++) {
			if (pile[p][h] == a) return;
		}
	}
}

void reset_pile(int p, int h) {
	for (int i = h + 1; i < pile[p].size(); i++) {
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h + 1);
}

void onto_pile(int p, int h, int p2) {
	for (int i = h; i < pile[p].size(); i++) {
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

void print(vector<int> box[]) {
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		if (box[i].empty()) {
			cout << endl;
			continue;
		}
		for (auto j = box[i].begin(); j != box[i].end(); j++) {
			printf(" %d", *j);
		}
		cout << endl;
	}
}

int main() {
	//#define FREOPEN
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pile[i].push_back(i);
	}
	while (cin >> s1 >> a >> s2 >> b) {
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa == pb) continue;
		if (s1 == "move") reset_pile(pa, ha);
		if (s2 == "onto") reset_pile(pb, hb);
		onto_pile(pa, ha, pb);
	}
	print(pile);



#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}