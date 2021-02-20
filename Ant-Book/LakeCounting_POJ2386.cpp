#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>

typedef long long LL;
using namespace std;

const int MAX_nm = 110;
char squ[MAX_nm][MAX_nm];
int n, m;

void DFS(int r, int c) {
	squ[r][c] = '.';
	for(int i=-1;i<=1;i++)
		for (int j = -1; j <= 1; j++) {
			int subr = r + i, subc = c + j;
			if (subr >= 1 && subr <= n && subc >= 1 && subc <= m && squ[subr][subc] == 'W')
				DFS(subr, subc);
		}
}

int main() {
	//#define FREOPEN
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> squ[i][j];
		getchar();
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (squ[i][j] == 'W') {
				DFS(i, j);
				sum++;
			}
		}
	}

	cout << sum << endl;


#ifdef FREOPEN
	fclose(stdin);
	fclose(stdout);
#endif // FREOPEN
	return 0;
}