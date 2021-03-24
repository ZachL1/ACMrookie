//
//  FenceRepair_POJ3253.cpp
//  Ant-Book
//
//  Created by PDP11 on 2021/3/24.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=20010;
int L[MAXN];

int main(){
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++) scanf("%d", L+i);

    long long sum=0;
    
    while(n>1){
        int min1=0,min2=1;
        if(L[min1]>L[min2]) swap(min1,min2);
        for(int i=0; i<n; i++){
            if(L[i]<L[min1]){
                min2=min1;
                min1=i;
            }
            else if(i!=min1 && L[i]<L[min2])
                min2=i;
        }
        sum+=L[min1]+L[min2];
        L[min2]+=L[min1];
        swap(L[min1], L[--n]);
    }
    cout << sum;
    
    return 0;
}
