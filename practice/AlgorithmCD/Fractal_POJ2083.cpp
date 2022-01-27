//
//  Fractal_POJ2083.cpp
//  workspace
//
//  Created by 段志超 20192902 on 2021/5/11.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn=730;
int x[maxn][maxn];
int dr[5]={0, -1, -1, 1, 1}, dc[5]={0, -1, 1, -1, 1};

void solve(int r, int c, int sn){
    if(sn==1) { // 递归边界
        x[r][c]=1;
        return ;
    }
    
    sn /= 3;
    for(int i=0; i<5; ++i){
        solve(r+dr[i]*sn, c+dc[i]*sn, sn);
    }
}

int main(){
    int n;
    while(cin>>n && n!=-1){
        memset(x, 0, sizeof(x));
        int sizen=(int)pow(3.0, n-1);
        
        solve(sizen/2+1, sizen/2+1, sizen);
        for(int i=1; i<=sizen; ++i){
            for(int j=1; j<=sizen; ++j){
                if(x[i][j]) printf("X");
                else printf(" ");
            }
            printf("\n");
        }
        printf("-\n");
    }
}
