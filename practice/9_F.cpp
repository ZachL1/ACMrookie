#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
int ab[maxn],bc[maxn];
LL abc[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", a+i);
    for(int i=0; i<n; ++i) scanf("%d", b+i);
    for(int i=0; i<n; ++i) scanf("%d", c+i);
    sort(a, a+n);sort(b, b+n);sort(c,c+n);

    int i=0,j=0;
    while(i<n){
        if(j==n) ab[i++]=0;
        else if(j<n && b[j]<=a[i]) ++j;
        else ab[i++]=n-j;
    }
    i=j=0;
    while(i<n){
        if(j==n) bc[i++]=0;
        else if(j<n && c[j]<=b[i]) ++j;
        else bc[i++]=n-j;
    }
    abc[n-1]=bc[n-1];
    for(i=n-2; i>=0; --i){
        abc[i]=abc[i+1]+bc[i];
    }
    LL ans=0;
    for(int i=0; i<n; ++i){
        ans+=abc[n-ab[i]];
    }
    cout << ans;
    return 0;
}
