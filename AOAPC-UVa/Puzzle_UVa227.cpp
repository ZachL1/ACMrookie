#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
#define maxn 5

char q[5][5];
using namespace std;
struct space{
	int x;
	int y;
} sp;
bool move(char m) {
	switch (m) {
	case 'A':
		if (sp.x - 1 < 0) return false;
		q[sp.x][sp.y] = q[sp.x - 1][sp.y];
		q[--sp.x][sp.y] = ' ';
		break;
	case 'B':
		if (sp.x + 1 >= maxn) return false;
		q[sp.x][sp.y] = q[sp.x + 1][sp.y];
		q[++sp.x][sp.y] = ' ';
		break;
	case 'L':
		if (sp.y - 1 < 0) return false;
		q[sp.x][sp.y] = q[sp.x][sp.y - 1];
		q[sp.x][--sp.y] = ' ';
		break;
	case 'R':
		if (sp.y + 1 >= maxn) return false;
		q[sp.x][sp.y] = q[sp.x][sp.y + 1];
		q[sp.x][++sp.y] = ' ';
		break;
	default:
		return false;
	}
	return true;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int times = 0;
	string stemp;
	bool first = true;
	while (getline(cin, stemp) && stemp != "Z") {
		/*cout << stemp.length() << endl;
		cout << (stemp[4] == ' ');*/
		_for(i, 0, stemp.length()) {
			q[0][i] = stemp[i];
		}
		
		/*if (stemp.length() == 4) q[0][4] = ' ';*/
		_for(i, 1, 5) {
			_for(j, 0, 5) {
				scanf("%c", &q[i][j]);
			}
			getchar();
		}
		_for(i, 0, 5) {
			_for(j, 0, 5) {
				if (q[i][j] == ' ') {
					sp.x = i;
					sp.y = j;
				}
			}
		}
		if (!first) cout << endl;
		if (first) first = false;
		printf("Puzzle #%d:\n", ++times);
		bool is = true;
		char m;
		while (scanf("%c", &m) && m != '0') {
			if (m == '\n') continue;
			if (!move(m)) {
				puts("This puzzle has no final configuration.");
				while (getchar() != '0') continue; // ¶ÁÈ¡Ê£Óà²Ù×÷
				is = false;
				break;
			}
		}
		if (is) {
			_for(i, 0, maxn) {
				_for(j, 0, maxn) {
					printf("%c%c", q[i][j], (j == maxn-1) ? '\n' : ' ');
				}
			}
		}
		//cout << endl;
		getchar();
	}
	return 0;
}