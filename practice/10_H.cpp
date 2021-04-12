//
//  10_H.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/8.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn];

int gcd(int a,int b){
    return !b ? a : gcd(b, a%b);
}
int main(){
    int n;scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", a+i);
    sort(a, a+n);
    
    int temp=a[1]-a[0];
    if(temp==0){
        cout << n;
        return 0;
    }
    for(int i=2; i<n; ++i){
        temp=gcd(temp, a[i]-a[i-1]);
        if(temp==1) break;
    }
    printf("%d", (a[n-1]-a[0])/temp+1 );
    return 0;
}
