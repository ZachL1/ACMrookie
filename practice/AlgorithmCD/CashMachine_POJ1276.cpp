//
//  CashMachine_POJ1276.cpp
//  workspace
//
//  Created by 段志超20192902 on 2021/5/13.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using  namespace std;
const int maxn=100005;
int dp[maxn], value[maxn];

int main(){
    int cash,n;
    while(~scanf("%d%d", &cash, &n)){
        memset(value, 0, sizeof(value));
        int nk, dk, cnt=1;
        for(int i=1; i<=n; ++i) {
            scanf("%d%d", &nk, &dk);
            for(int j=1; j<=nk; j<<=1){
                value[cnt++]=j*dk;
                nk-=j;
            }
            value[cnt++]=nk*dk;
        }
        
        int ans=0;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<cnt; ++i){
            for(int j=cash; j>=value[i]; --j){
                dp[j]=max(dp[j], dp[j-value[i]]+value[i]);
                ans=max(ans, dp[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
