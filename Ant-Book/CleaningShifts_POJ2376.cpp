//
//  CleaningShifts_POJ2376.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/25.
//

#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=25005;
struct cow{
    int beg,end;
};
cow cows[MAXN];

bool cmp(cow a, cow b){
    return a.end>b.end;
}

int main(){
    int N,T;
    cin>>N>>T;
    
    for(int i=0; i<N; i++) scanf("%d%d", &cows[i].beg, &cows[i].end);
    sort(cows, cows+N, cmp);
    int mmin=0;
    for(int i=0; i<N; i++){
        if(cows[i].beg<cows[mmin].beg) mmin=i;
    }
    if(cows[mmin].beg>1){
        cout<<-1;
        return 0;
    }
    
    int ans=1;
    while(cows[mmin].end < T){
        int temp=mmin;
        for(int i=0; i<mmin; i++){
            if(cows[i].beg <= cows[mmin].end+1){
                mmin=i;
                ans++;
                break;
            }
        }
        if(mmin==temp){
            cout << -1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
