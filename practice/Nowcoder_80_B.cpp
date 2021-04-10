//
//  Nowcoder_80_B.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/9.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#define mod 998244353
using  namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL a[maxn];
LL b[maxn];
LL c[maxn];

int main(){
    int n=0;
    cin>>n;
    LL suma=0,sumb=0;
    for(int i=0; i<n; ++i){
        scanf("%lld", a+i);
        suma += a[i];
    }
    for(int i=0; i<n; ++i){
        scanf("%lld", b+i);
        sumb += b[i];
//        if(i!=0) c[0]=(c[0]+(suma-a[0])*b[i]%mod)%mod;
    }
    c[0] = ((suma-a[0])%mod) * ((sumb-b[0])%mod) % mod;
    c[1] = ((b[0]%mod) * ((suma-a[1])%mod) + (a[0]%mod)*((sumb-b[1])%mod) - a[0]*b[0])%mod;
    c[2] = (a[0]*b[1] + a[1]*b[0])%mod;

//    c[0] = ( ((suma-a[0])%mod) * ((sumb-b[0])%mod) )%mod;
//    c[1] = (b[0] * ((suma-a[1])%mod) + a[0]*((sumb-b[1])%mod) - a[0]*b[0])%mod;
//    c[2] = (a[0]*b[1] + a[1]*b[0])%mod;
    for(int i=0; i<n; ++i) printf("%lld ", c[i]);
    return 0;
}
