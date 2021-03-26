//
//  YogurtFactory.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/26.
//
//  打ACM的属实都不是人，这样的算法怎么想出来？？？？？
//  我一度怀疑自己智商 😭

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn=1e4+5;
int c[maxn],y[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int n,s;
    cin>>n>>s;
    
    for(int i=0; i<n; i++) scanf("%d%d", c+i, y+i);
    
    for(int i=1; i<n; i++) c[i]=min(c[i],c[i-1]+s);
    
    LL sum=0;
    for(int i=0; i<n; i++) sum+=c[i]*y[i];
    cout << sum;
    
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
