#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> p;

const int MAXN = 100;
string maze[MAXN];
string setp[MAXN][MAXN];
queue<p> q;
int n, m;
vector<string> ans;

void bfs(int r, int c) {
	int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	char way[4] = { 'R','L','D','U' };

	q.push(make_pair(r, c));
	while (!q.empty()) {
		p i = q.front(); q.pop();
		int x = i.first, y = i.second;
		if (x == 29 && y == 49) ans.push_back(setp[x][y]);
		maze[x][y] = '1';

		for (int j = 0; j < 4; j++) {
			int nx = x + d[j][0], ny = y + d[j][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '1') {
				q.push(make_pair(nx, ny));
				setp[nx][ny] = setp[x][y] + way[j];
			}
		}
	}
}

bool cmp(string s1, string s2) {
	if (s1.length() != s2.length()) return s1.length() < s2.length();
	else return s1 < s2;
}

int main() {
#define FREOPEN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//cin >> n >> m;
	n = 30, m = 50;
	for (int i = 0; i < n; i++) cin >> maze[i];
	bfs(0, 0);

	sort(ans.begin(), ans.end(), cmp);
	cout << *ans.begin();


#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}