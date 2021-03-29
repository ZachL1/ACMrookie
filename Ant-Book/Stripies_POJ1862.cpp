//
//  Stripies_POJ1862.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/29.
//
//  注意这道题应该优先对最大的两个进行合并，得到的最终结果就是最小的

//  设：n=3，三个物品的重量分比为：a，b，c， 合并之后最小重量为w。
//  则w = 2 * sqrt( a* 2 * sqrt(b * c) )
//  化简后的 w^2/8 = sqrt(a*a*b*c)， 此式可得 a 取最小时 w 的值最小。
//  归纳总结，n个物品每次取最大的两个合并，总重最小。

//  另外需要注意的是，不需要用到优先队列
//  因为必然有 2*sqrt(a*b) >= min(a,b)
//  从小到大排好序，计算结果放结尾，同时数组长度减1即可

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=105;
double m[maxn];

int main(){
    int N;
    cin>>N;
    
    for(int i=0; i<N; i++) scanf("%lf", m+i);
    sort(m,m+N);
    
    while(--N>0){
        m[N-1]=2*sqrt(m[N]*m[N-1]);
    }
    printf("%.3f", m[0]);
    
    return 0;
}
