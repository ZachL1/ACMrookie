//
//  CommonSubsequence_POJ1458.cpp
//  workspace
//
//  Created by 段志超 20192902 on 2021/5/13.
//

#include <cstdio>
#include <iostream>

using namespace std;
const int maxn=505;
int dp[maxn][maxn];

int main(){
    string s1, s2;
    while(cin>>s1>>s2){
        for(int i=1; i<=s1.length(); ++i){
            for(int j=1; j<=s2.length(); ++j){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[s1.length()][s2.length()] << endl;
    }
    return 0;
}
