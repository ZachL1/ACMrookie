//
//  StallReservations.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/26.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn=50005;
struct cow{
    int beg, end, owntime;
//    bool operator< (cow b){
//        return beg<b.beg;
//    }
};
bool cmp(cow a, cow b){
    return a.beg<b.beg;
}
cow cows[maxn];

priority_queue<int> endtime;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d%d", &cows[i].beg, &cows[i].end);
        cows[i].owntime=0;
    }
    sort(cows,cows+n,cmp);
    
    int time=1;
    for(; time<=n; time++){
        int now=0;
        bool nocontinue=true;
        for(int i=0; i<n; i++){
            if(cows[i].owntime==0 && cows[i].beg>now){
                nocontinue=false;
                now=cows[i].end;
                cows[i].owntime=time;
            }
        }
        if(nocontinue) break;
    }
    cout << time-1 << endl;
    for(int i=0; i<n; i++) printf("%d\n", cows[i].owntime);
    
    return 0;
}
