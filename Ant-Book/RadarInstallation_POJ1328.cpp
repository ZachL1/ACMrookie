//
//  RadarInstallation_POJ1328.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/25.
//
// 起初看题的时候一直有一个误区, 总想通过分析雷达关于岛的位置来确定范围,
// 后来发现其实加上一点儿逆向思维, 通过考虑岛来确定雷达的范围其实会更简单
//
// 具体来说, 考虑一下每个小岛被覆盖时雷达的区间, 最后就把各个小岛转化为了一个个区间,
// 我们的任务就是求最少的点, 使得所有的线段都被覆盖到, 直接顺序枚举+贪心即可
// ————————————————
// 题解：https://blog.csdn.net/a1097304791/article/details/83018053

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
//const double eps=1e-5;
const int maxn=1005;
struct radar{
    double left,right;
};
radar radars[maxn];
int n,d;

void computer(int x, int y, radar &r){
    double dx=sqrt((double)(d*d-y*y));
    r.left=x-dx;
    r.right=x+dx;
}
bool cmp(radar a, radar b){
    if(a.right!=b.right)
        return a.right<b.right;
    else
        return a.left<b.left;
}
int main(){
//#define Redirection
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    
    int x,y,times=1;
    while(scanf("%d%d", &n,&d) && n){
        printf("Case %d: ", times++);
        int ans=1;
        for(int i=0; i<n; i++) {
            scanf("%d%d", &x, &y);
            if(y>d) ans=-1;
            else computer(x, y, radars[i]);
        }
        if(ans<0){
            cout << ans << endl;
            continue;
        }
        sort(radars, radars+n, cmp);
        int nowi=0;
        for(int i=1; i<n; i++){
            if(radars[i].left>radars[nowi].right){
                ans++;
                nowi=i;
            }
        }
        cout << ans << endl;
    }
    
#ifdef Redirection
    fclose(stdin);
//    fclose(stdout);
#endif
    return 0;
}
