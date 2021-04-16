//
//  GoneFishing_POJ1042.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/15.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
struct lake{
    int i;
    int f,d;
    bool operator< (const lake& b) const{
        if(f==b.f) return i>b.i;
        return f<b.f;
    }
};
const int maxn=30;
lake lak[maxn];
int t[maxn], ans[maxn];
int n, h, mmax=0;

inline void greed(int end, int tim){
    priority_queue<lake> lakes;
    for(int i=0; i<=end; ++i){
        lakes.push(lak[i]);
    }
    
    int sum=0, temp[maxn];
    memset(temp, 0, sizeof(temp));
    while(!lakes.empty() && tim>0){
        lake fish=lakes.top(); lakes.pop();
        sum+=fish.f;
        ++temp[fish.i]; --tim;
        fish.f = max(0,fish.f-fish.d);
        lakes.push(fish);
    }
    
    if(sum>mmax){
        mmax=sum;
        copy(temp, temp+n, ans);
    }
    else if(sum==mmax){
        // 如果有多种方案，优先选前面的湖时间长的
        for(int i=0; i<n; ++i){
            if(temp[i]<ans[i]) break;
            else if(temp[i]>ans[i]){
                copy(temp, temp+n, ans);
                break;
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int fist=0;
    while((scanf("%d", &n) != EOF) && n){
        mmax=0; memset(ans, 0, sizeof(ans)); // 以后一定一定要记得清空数组！！
        scanf("%d", &h);
        h *= 12; // 把小时换算成tic，一个tic五分钟
        for(int i=0; i<n; ++i) {
            scanf("%d", &lak[i].f);
            lak[i].i=i;
        }
        for(int i=0; i<n; ++i) scanf("%d", &lak[i].d);
        for(int i=1; i<n; ++i) scanf("%d", t+i);
        
        // 枚举所有可能停下来的位置
        int temp=h;
        for(int i=0; i<n; ++i){
            temp -= t[i]; //总时间减去路上的耗费，剩下来的时间都用来钓鱼
            // 注意，并不需要考虑“顺序”！
            // 虽然对同一个湖重复的pop push，看上去貌似在来回走动，但其实只是为了找出最优情况下每个湖的停留时间，实际“钓鱼”时，按照这个最优时间停留即可
            greed(i, temp);
        }
        
        if(fist++) putchar('\n');
        for(int i=0; i<n; ++i){
            printf("%d%s", ans[i]*5, (i==n-1) ? "\n" : ", ");
        }
        printf("Number of fish expected: %d\n", mmax);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
