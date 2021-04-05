//
//  Tiling_POJ2506.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/1.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=255; // 最大输入 n
const int maxi=200; // 大整数最大长度
// 定义大整数类
struct bigInt{
    int n[maxi];
    // 大整数加法
    bigInt operator+ (const bigInt &m) const{
        bigInt ans; // 定义临时大整数存储相加结果
        memset(ans.n, 0, sizeof(ans.n)); // 临时大整数置零
        
        int temp;
        for(int i=0; i<maxi; i++){
            temp=n[i]+m.n[i];
            ans.n[i]+=temp;
            if(ans.n[i]>9) {
                ans.n[i]%=10;
                ans.n[i+1]++;
            }
        }
        return ans;
    }
};

int n;
bigInt dp[maxn];

// 大整数输出
const ostream& operator<< (const ostream &os, const bigInt &b) {
    int beg=maxi-1; // 找到大整数的最高位
    for(; beg>=0; beg--){
        if(b.n[beg]) break;
    }
    while(beg>=0){ // 从最高位开始输出
        printf("%d",b.n[beg--]);
    }
    return os;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // 打表
    dp[0].n[0]=1; // n=0时答案是1！！这个点太坑了
    dp[1].n[0]=1;
    dp[2].n[0]=3;
    for(int i=3; i<maxn; i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-2];
    }
    
    while(scanf("%d",&n) != EOF){
        cout << dp[n];
        cout << endl;
    }
    
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
