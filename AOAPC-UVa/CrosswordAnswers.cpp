#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
typedef long long LL;
using namespace std;

char ar[12][12];
int st[12][12];
bool puted[12][12];

bool is_st(int i, int j) {
    if (ar[i][j]!='*' && (!isalpha(ar[i - 1][j]) || !isalpha(ar[i][j - 1])))
        return true;
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int r, c;
    int times=0;
    while (scanf("%d", &r) && r) {
        memset(st, 0, sizeof(st));
        //cout << sizeof(st)/sizeof(int);
        memset(puted, 0, sizeof(puted));

        scanf("%d\n", &c);
        _rep(i, 1, r) {
            _rep(j, 1, c) {
                scanf("%c", &ar[i][j]);
            }
            getchar();
        }
        int count = 0;
        _rep(i, 1, r) {
            _rep(j, 1, c) {
                if (is_st(i, j)) st[i][j] = ++count;
            }
        }
        
        if (times) cout << endl;
        printf("puzzle #%d:\n", ++times);
        puts("Across");
        _rep(i, 1, r) {
            _rep(j, 1, c) {
                if (st[i][j]) {
                    printf("%3d.", st[i][j]);
                    while (j <= c && ar[i][j] != '*') {
                        putchar(ar[i][j++]);
                        //puted[i][j] = true;
                    }
                    cout << endl;
                }
            }
        }
        puts("Down");
        _rep(i, 1, r) {
            _rep(j, 1, c) {
                if (st[i][j] && !puted[i][j]) {
                    printf("%3d.", st[i][j]);
                    int ii = i;
                    while (ii <= r && ar[ii][j] != '*') {
                        putchar(ar[ii][j]);
                        puted[ii++][j] = true;
                    }
                    cout << endl;
                }
            }
        }

    }

    return 0;
}