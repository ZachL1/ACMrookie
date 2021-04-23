#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=1e4+5;
struct people{
    int i,cnt;
    LL mon;
    bool operator< (const people& b) const {
        if(mon==b.mon){
            if(cnt==b.cnt) return i<b.i;
            return cnt>b.cnt;
        }
        return mon>b.mon;
    }
}peop[maxn];
int main(){
    int n;cin>>n;
    for(int i=1; i<=n; ++i) peop[i].i=i;
    for(int i=1; i<=n; ++i){
        int k;cin>>k;
        LL j,p;
        while(k--){
            scanf("%lld%lld", &j, &p);
            peop[i].mon-=p;
            peop[j].mon+=p;
            ++peop[j].cnt;
        }
    }
    sort(peop+1, peop+n+1);
    for(int i=1; i<=n; ++i){
        printf("%d %.2f\n", peop[i].i, double(peop[i].mon)/100);
    }
    return 0;
}