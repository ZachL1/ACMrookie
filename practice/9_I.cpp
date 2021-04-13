#include<cstdio>
#include<iostream>

using namespace std;
const int maxn=1e3+5;
char a[maxn][maxn];
int v[maxn][maxn];

int da[]={-1,0,1,0},db[]={0,-1,0,1};
void dfs(int i, int j, int &ba){
    v[i][j]=1;
    if(a[i-1][j]=='#' && a[i+1][j]=='#'
               && a[i][j-1]=='#' && a[i][j+1]=='#') ba=0;
    for(int d=0; d<4; ++d){
        int ni=i+da[d],nj=j+db[d];
        if(a[ni][nj]=='#' && !v[ni][nj]) dfs(ni,nj,ba);
    }
}
int main(){
    int n;cin>>n;
    for(int i=0; i<n; ++i){
        getchar();
        for(int j=0; j<n; ++j){
            scanf("%c", &a[i][j]);
        }
    }
    int aans=0;
    for(int i=1; i<n-1; ++i){
        for(int j=1; j<n-1; ++j){
            if(a[i][j]=='#' && !v[i][j]){
                int ba=1;
                dfs(i,j,ba);
                aans+=ba;
            }
        }
    }
    cout << aans;
    return 0;
}
