//
//  PropertyDistribution_Aizu0118.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/31.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn=105;
int cnt[maxn][maxn];
char a[maxn][maxn];
int h,w;

void dfs(char c, int x, int y){
    if(x<0 || x>=h || y<0 || y>=w || cnt[x][y] || a[x][y]!=c) return;
    
    cnt[x][y]=1;
    dfs(c,x-1,y);
    dfs(c,x+1,y);
    dfs(c,x,y-1);
    dfs(c,x,y+1);
}

int main(){
    while(scanf("%d%d", &h, &w)!=EOF && (h||w)){
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<h; i++){
            getchar();
            for(int j=0; j<w; j++){
                scanf("%c", &a[i][j]);
            }
        }
        
        int ans=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!cnt[i][j]){
                    dfs(a[i][j], i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
