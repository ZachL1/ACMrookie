#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1005;
int book[maxn], times[maxn];

int main(){
    int n;cin>>n;
    
    int ind, h, m, at;
    for(int i=0; i<n; ++i){
        memset(book, 0, sizeof(book));
        memset(times, 0, sizeof(times));
        int cnt=0, sum=0;
        while(scanf("%d %*c %d:%d", &ind, &h, &m) && ind){
            at=h*60+m;
            if(book[ind]==0){
                // 如果书没有被借走
                book[ind]=1;//1表示被借走了
                times[ind]=at;
            }
            else{
                book[ind]=0;
                ++cnt;
                sum+=at-times[ind];
            }
        }
        printf("%d %.0f\n", cnt, (cnt==0) ? 0 : (double)sum/cnt);
    }
    
    return 0;
}