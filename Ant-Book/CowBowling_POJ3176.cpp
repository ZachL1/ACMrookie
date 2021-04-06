//
//  CowBowling_POJ3176.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/6.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=355;
int dp[maxn][maxn];

int main(){
    int n;
    cin>>n;
    
    int temp;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            scanf("%d", &temp);
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+temp;
        }
    }
    int mmax=0;
    for(int i=1; i<=n; ++i)
        if(dp[n][i]>mmax) mmax=dp[n][i];
    cout << mmax;
    
    return 0;
}
