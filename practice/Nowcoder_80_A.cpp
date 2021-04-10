//
//  Nowcoder_80.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/9.
//

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn=1e6+5;
int a[maxn];

int main(){
    int len=0, sum=0;
    for(int i=0; scanf("%1d", a+i)!=EOF; ++i, ++len){
        if(a[i] && (!i || !a[i-1])) ++sum;
    }
    bool temp=false;
    if((a[0]&&!a[1]) || (!a[len-2]&&a[len-1])) temp=true;
    for(int i=1; i<len-1; ++i){
        if((a[i] != a[i-1]) && (a[i]!=a[i+1])) temp=true;
    }
    if(temp) --sum;
    cout << sum;
    return 0;
}
