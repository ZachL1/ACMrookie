//
//  RedAndBlack_POJ1979.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/31.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn=25;
int feat[maxn][maxn]; //0表示没走过，1表示走过了
char tiles[maxn][maxn];
int w,h;
//struct man{// 人的位置
//    int x,y;
//}
int dfs(int x,int y){
    if(x<0 || x>=h || y<0 || y>=w || tiles[x][y]=='#' || feat[x][y]) return 0;
    
    feat[x][y]=1;
    return 1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
}

int main(){
    while(scanf("%d%d", &w, &h)!=EOF && (w||h)){
        memset(feat, 0, sizeof(feat)); //置零
        int x=0,y=0;//人的位置
        for(int i=0; i<h; i++){
            getchar();
            for(int j=0; j<w; j++){
                scanf("%c", &tiles[i][j]);
                if(tiles[i][j]=='@') {
                    x=i;
                    y=j;
                }
            }
        }
        
        cout << dfs(x,y) << endl;
    }
    return 0;
}
