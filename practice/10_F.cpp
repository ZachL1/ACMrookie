//
//  10_F.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/8.
//

#include <cstdio>
#include <iostream>

inline bool yes(int num){
    int temp;
    while(num){
        temp=num%10;
        if(temp<3 || temp==9) return true;
        num/=10;
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=1; i<=n; ++i){
        if(yes(i)) ans+=i;
    }
    printf("%d", ans);
    return 0;
}
