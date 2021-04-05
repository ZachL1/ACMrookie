//
//  WorldCupNoise_POJ1953.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/1.
//

#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;
const int maxn=46;
LL ans0[maxn], ans1[maxn];
int n;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int m;
    cin>>m;
    
    // 打表
    ans0[1]=1;ans1[1]=1;
    for(int i=2; i<maxn; i++){
        ans0[i]=ans0[i-1]+ans1[i-1];
        ans1[i]=ans0[i-1];
    }
    
    for(int times=1; times<=m; times++){
        scanf("%d", &n);
        printf("Scenario #%d:\n", times);
        
        cout << ans0[n]+ans1[n] << endl << endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
