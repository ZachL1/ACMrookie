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
int setp[MAXN][MAXN];
queue<p> q;
int n, m;

int bfs(int r, int c) {
	int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

	q.push(make_pair(r, c));
	while (!q.empty()) {
		p i = q.front(); q.pop();
		int x = i.first, y = i.second;
		if (maze[x][y] == 'G') return setp[x][y];
		maze[x][y] = '#';
		
		for (int j = 0; j < 4; j++) {
			int nx = x + d[j][0], ny = y + d[j][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#') {
				q.push(make_pair(nx, ny));
				setp[nx][ny] = setp[x][y] + 1;
			}
		}
	}
	return 0;
}

int main() {
	#define FREOPEN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> maze[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(maze[i][j]=='S'){
				cout << bfs(i, j);
				break;
			}



#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}