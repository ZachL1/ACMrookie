#include <bits/stdc++.h>

using namespace std;
int piao[4][4], flag[10];
int ans[25]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
int main(){
    int x,y;
    for(int i=1; i<4; ++i){
        for(int j=1; j<4; ++j){
            scanf("%d", &piao[i][j]);
            flag[piao[i][j]]=1;
            if(!piao[i][j]){
                x=i;y=j;
            } 
        }
    }
    for(int i=1; i<10; ++i)
        if(!flag[i]) piao[x][y]=i;
    
    for(int i=0; i<3; ++i){
        scanf("%d%d", &x, &y);
        cout << piao[x][y] << endl;
    }
    int sum=0, ch;
    cin>>ch;
    if(ch<4){
        for(int i=1; i<4; ++i)
            sum+=piao[ch][i];
    }
    else if(ch<7){
        for(int i=1; i<4; ++i)
            sum+=piao[i][ch-3];
    }
    else if(ch==7){
        for(int i=1,j=1; i<4; ++i,++j)
            sum+=piao[i][j];
    }
    else{
        for(int i=1,j=3; i<4; ++i,--j)
            sum+=piao[i][j];
    }
    cout << ans[sum] << endl;
    return 0;
}