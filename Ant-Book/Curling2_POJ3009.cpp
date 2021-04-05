//
//  Curling2.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/1.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=25;
const int INF=11;
int squ[maxn][maxn],w,h;
struct point{
    int x,y;
}star,stop;

int xd[4]={-1,0,1,0};
int yd[4]={0,-1,0,1};
int dfs(int dx, int dy, int x, int y, int cnt, bool isstop){
    if(squ[x+dx][y+dy]==3){
        return cnt;
    }
    
    if(isstop){
        int ans=INF;
        for(int i=0; i<4; i++){
            if(x+xd[i]>=0 && x+xd[i]<h && y+yd[i]>=0 && y+yd[i]<w
               && squ[x+xd[i]][y+yd[i]]==1) continue;
            int temp=dfs(xd[i],yd[i],x+xd[i],y+yd[i],cnt+1,false);
            if(temp>0 && temp<ans) ans=temp;
        }
        return ans;
    }
    else if(x+dx<0 || x+dx>=h || y+dy<0 || y+dy>=w || cnt>10){
        return -1;
    }
    else if(squ[x+dx][y+dy]==1){
        squ[x+dx][y+dy]=0;
        return dfs(0,0,x,y,cnt,true);
    }
    else{
        return dfs(dx,dy,x+dx,y+dy,cnt,isstop);
    }
    
}

int main(){
    while(scanf("%d%d", &w, &h)!=EOF && (w||h)){
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &squ[i][j]);
                if(squ[i][j]==2){
                    star.x=i;star.y=j;
                }
            }
        }
        
//        int ans=INF;
//        for(int i=0; i<4; i++){
//            if(star.x+xd[i]>0 && star.x+xd[i]<=h && star.y+yd[i]>0 && star.y+yd[i]<=w
//               && squ[star.x+xd[i]][star.y+yd[i]]==1) continue;
//            int temp=dfs(xd[i],yd[i],star.x,star.y,1);
//            if(temp>0 && temp<ans) ans=temp;
//        }
        int ans=dfs(0,0,star.x,star.y,1,true);
        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
