//
//  Nowcoder_80_C.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/9.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#define mod 100019
using namespace std;
typedef long long LL;
const int maxn=1e8+5;
int dp[10];
int ans[maxn];

int main(){
//    freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    for(int i=1; i<10; ++i) dp[i]=1;
    for(int i=2; i<=n; ++i){
        for(int j=9; j>=0; --j){
            for(int k=0; k<j; --k){
                dp[j]+=dp[k];
            }
        }
        for(int j=2; j<10; ++j){
            dp[j]=(dp[j]+dp[j-1]) % mod;
        }
//        printf("%d,", dp[9]);
    }
    int ans=0;
    for(int i=1; i<10; ++i) ans=(ans+dp[i])%mod;
    cout << ans;
//    fclose(stdout);
    return 0;
}
