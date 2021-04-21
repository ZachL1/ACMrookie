#include <cstdio>
#include <iostream>

using namespace std;
const int maxn=1e5+5;
int pr[maxn];//到达门i的这条路前面的那条门  pr[i]->i
int dist[maxn], path[maxn];//在求解入口到门i的距离dist[i]时，中途会经过一些门，这些门肯定不是要求解的门，剪枝

int main(){
    int n,k,temp; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>k;
        while(k--){
            scanf("%d", &temp);
            pr[temp]=i;
        }
    }
    int ans=0;
    for(int i=1; i<=n; ++i){
        if(!path[i]){
            int p=pr[i];
            while(p){ //如果前面还有门，则向前遍历，直到出口
                path[p]=1; //把路上的门都剪掉
                p=pr[p]; //到上一扇门
                ++dist[i];
            }
        }
        if(dist[i]>dist[ans]) ans=i;
    }
    cout << ans << endl;
    return 0;
}
