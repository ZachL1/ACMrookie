//
//  10_I.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/8.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
using LL=long long;
const int maxn=2e5+5;
int a[maxn];

bool cmp(int& a, int& b){
    return a>b;
}
//int main(){
//    int n,m;
//    scanf("%d%d", &n, &m);
//    for(int i=0; i<n+m+1; ++i) scanf("%d", a+i);
//    sort(a,a+n+m+1);
//    // 有负数，先利用减号把负数取正
//    for(int i=0; i<n+m+1 && m && a[i]<0; ++i){
//        a[i]=~a[i]+1;
//        ++n;--m;
//    }
//    sort(a,a+n+m+1,cmp);
//
//    long long ans=0;
//    for(int i=0; i<=n; ++i) ans+=a[i];
//    for(int i=n+1; i<n+m+1; ++i) ans-=a[i];
//    cout << ans;
//    return 0;
//}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    int N=n+m+1, fu=0;
    for(int i=0; i<N; ++i) {
        scanf("%d", a+i);
        if(a[i]<0) ++fu;
    }
    LL ans=0;
    if(m==0){
        // 没有减号，直接相加
        for(int i=0; i<N; ++i) ans += a[i];
    }
    else if(fu==0){
        // 有减号但是没有负号，所有数相加，除了最小的那个
        int mmin=a[0];
        for(int i=0; i<N; ++i){
            ans += a[i];
            mmin = (a[i]<mmin) ? a[i] : mmin;
        }
        ans -= 2*mmin;
    }
    else if(fu==N){
        // 最容易忽略的一种情况，全为负数
        // 排除上述2种情况，所以只要有减号，一定是其他所有数的绝对值-最大负数的绝对值
        // ！！最大负数，即绝对值最小的数
        int mmax=a[0];
        for(int i=0; i<N; ++i){
            ans+=~a[i]+1;
            mmax=(a[i]>mmax) ? a[i] : mmax;
        }
        ans+=mmax*2;
    }
    else{
        // 其他情况，所有数取正,然后相加
        for(int i=0; i<N; ++i){
            ans += (a[i]<0) ? -a[i] :a[i];
        }
    }
    cout << ans;
    return 0;
}
