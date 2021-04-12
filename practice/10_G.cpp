//
//  10_G.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/8.
//

#include <cstdio>
#include <iostream>

using namespace std;
const int maxm=20;
int a[maxm];

int main(){
    int n;
    scanf("%d", &n);
    
    a[0]=1;
    for(int i=1; i<maxm; ++i){
        a[i]=a[i-1]*2;
    }
    
    int ans=0, mmax=0, temp=0, ttemp=0, t;
    for(int j=0; ttemp<n; ++j){
        temp=0;
        for(int ij=0; ttemp<n && ij<a[j]; ++ij){
            scanf("%d", &t);
            temp+=t;
            ++ttemp;
        }
        if(temp>mmax){
            mmax=temp;
            ans=j;
        }
    }
    cout << ans+1;
    return 0;
}
