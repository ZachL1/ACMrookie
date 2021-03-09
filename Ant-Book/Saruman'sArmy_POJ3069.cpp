//
//  Saruman'sArmy_POJ3069.cpp
//  Ant-Book
//
//  Created by PDP11 on 2021/3/9.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>

typedef long long LL;
using namespace std;

const int MAXN = 1010;
int n, r, x[MAXN];

int slove(int i){
    int newi=i;
    for(; newi<n && x[newi]<=x[i]+r; newi++);
    i=newi-1;
    for(; newi<n && x[newi]<=x[i]+r; newi++);
    return newi;
}

int main() {
//    #define FREOPEN
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    while(scanf("%d%d", &r, &n) && n!=-1){
        memset(x, 0, sizeof(x));
        for(int i=0; i<n; i++){
            scanf("%d", x+i);
        }
        sort(x, x+n);
        
        int sum=0;
        for(int now=0; now<n; ){
            now = slove(now);
            sum++;
        }
        cout << sum << endl;
    }

#ifdef FREOPEN
    fclose(stdin);
    fclose(stdout);
#endif // FREOPEN
    return 0;
}
