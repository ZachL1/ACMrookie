//
//  CharmBracelet.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/8.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=3405, maxm=12885;
//int dp[maxn][maxm];
int dp[maxm];
short w[maxn],d[maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        scanf("%hd%hd", w+i, d+i);
    }
    for(int i=1; i<=n; ++i){
//        for(int j=1; j<=m; ++j){
//            if(j>=w[i]) dp[i][j]=max(dp[i-1][j-w[i]]+d[i], dp[i-1][j]);
//            else dp[i][j]=dp[i-1][j];
//        }
//        本题如用记忆型递归，需要一个很大的二维数组，会超内存。
//        注意到这个二维数组的下一行的值，只用到了上一行的正上方及左边的值，
//        因此可用滚动数组的思想，只要一行即可。即可以用一维数组，用“人人为我” 递推型动归实现。
        for(int j=m; j>=w[i]; --j){
            dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
        }
    }
    cout << dp[m];
    return 0;
}
