//
//  Allowance_POJ3040.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/29.
//
//  直接暴力贪心会超时，需要优化
//
//  每一次求出一种方案之后，下一次很可能依旧是这种方案
//  因此可以把这一次方案记录下来，判断每种硬币剩下的数量够不够再做一次这种方案
//  如果够，下一次就不用模拟了，直接减少对应数量的硬币数，然后ans++就行
//  只有当当前硬币数量不足以维持这种方案时，才模拟产生新的方案


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
struct coin{
    int value,num;
    int cnt;
    bool operator< (const coin &b) const{
        return value>b.value;
    }
};
const int maxn=25;
coin coins[maxn];

int main(){
    int N,C;
    cin>>N>>C;
    for(int i=0; i<N; i++){
        scanf("%d%d", &coins[i].value, &coins[i].num);
    }
    sort(coins, coins+N);

    LL sum=0;
    bool flag=true;
    while(true){
        int need=C,cnt;
        if(flag){
            for(int i=0; i<N; i++){
                // cnt用来记录当前方案使用对应硬币的数量
                coins[i].cnt=cnt=min(need/coins[i].value, coins[i].num);
                coins[i].num-=cnt;
                need-=cnt*coins[i].value;
            }
            
            int i=N-1;
            for(; i>=0; i--){
                cnt=min((need+coins[i].value-1)/coins[i].value, coins[i].num);
                coins[i].cnt+=cnt;
                coins[i].num-=cnt;
                need-=cnt*coins[i].value;
                
                if(need<=0) break;
            }
        }
        else{ // 贪心加速
            for(int i=0; i<N; i++){
                coins[i].num-=coins[i].cnt;
            }
            need=0;
        }
        
        // 判断当前硬币能不能够再做一遍当前方案
        flag=false;
        for(int i=0; i<N; i++)
            if(coins[i].cnt>coins[i].num){
                flag=true;
                break;
            }
        
        sum++;
        if(need>0) break;
    }
    cout<<sum-1;
    
    return 0;
}
