//
//  ProtectingTheFlowers_POJ3262.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/30.
//
//那么其实我第一感觉就是跟比率有关。
//然后简略的证了一下。
//
//假设序列都由二元组组成，二元组是由D和T组成，那么对一个序列有相邻的两头牛是这样的
//..........(a, b) ,(c, d)....................
//如果(a,b)和(c,d)交换位置了
//变成新序列
//..........(c,d),(a,b).....................
//假设在这之前FJ已经花了x时间了。
//那么赶完这两头牛的损失的量就分别为
//x*b + (x + a ) * d
//x*d +(x + c) * b
//二者做差
//得到ad - bc
//若ad < bc 则有第一个序列优于第二个
//
//那么这不就是比率么
//那么对于任意的序列，我们都可以通过若干次这种相邻的交换使得序列变成最优的。
//————————————————
//版权声明：题解为CSDN博主「sdj222555」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/sdj222555/article/details/10284181

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
struct cow{
    LL t,d;
    bool operator< (const cow &b) const{
        return t*b.d < d*b.t;
    }
};
const int maxn=1e5+5;
cow cows[maxn];

int main(){
    int n;
    cin>>n;
    LL cost=0;
    for(int i=0; i<n; i++){
        scanf("%lld%lld", &cows[i].t, &cows[i].d);
        cost+=cows[i].d;
    }
    sort(cows, cows+n);
    
    LL sum=0;
    for(int i=0; i<n; i++){
        cost-=cows[i].d;
        sum+=cost*cows[i].t*2;
    }
    cout<<sum;
    
    return 0;
}
