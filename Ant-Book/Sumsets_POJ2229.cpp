////
////  Sumsets.cpp
////  workspace
////
////  Created by PDP11 on 2021/4/6.
////
//
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//const int maxn=1e6+5;
//int dp[maxn];
//
//int main(){
//    const int maxm=log(1e6)/log(2)+5;
//    int two[maxm];
//
//    two[0]=1;
//    for(int i=1; i<maxm; ++i){
//        two[i]=two[i-1]*2;
//    }
//    
//    int n;
//    cin>>n;
//    dp[0]=1;dp[1]=1;
//    for(int i=2; i<=n; ++i){
//        for(int j=0; i>=two[j]; ++j){
//            dp[i]=(dp[i]+dp[i-two[j]]) % int(1e9);
//        }
//    }
//    cout << dp[n];
//    return 0;
//}
