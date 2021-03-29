//
//  StallReservations_POJ3190.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/26.
//
//  特别注意！！！
//  对于自定义类型的优先队列，即使重载了小于比较，但默认还是大顶堆（大的优先）
//  注意重载小于号时返回 end>b.end 即可实现大的优先！！！


#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn=50005;

struct code{
    int cnt,end;
    //  特别注意！！！
    //  对于自定义类型的优先队列，即使重载了小于比较，但默认还是大顶堆（大的优先）
    //  注意重载小于号时返回 end>b.end 即可实现大的优先！！！
    bool operator< (const code &b) const {
        return end>b.end;
    }
    code(int c=0,int e=0){
        cnt=c;end=e;
    }
};
priority_queue<code, vector<code> > pque;

struct cow{
    int beg,end;
    int index;
    bool operator< (const cow &b) const {
        return beg<b.beg;
    }
};
cow cows[maxn];
cow sortcows[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d%d", &cows[i].beg, &cows[i].end);
        sortcows[i]=cows[i];
        sortcows[i].index=i;
    }
    sort(sortcows,sortcows+n);
    
    int time=1;
    code c(time,0);
    pque.push(c);
    for(int i=0; i<n; i++){
        code co=pque.top();pque.pop();
        if(co.end<sortcows[i].beg){
            co.end=sortcows[i].end;
            cows[sortcows[i].index].index=co.cnt;
        }
        else{
            code newco(++time,sortcows[i].end);
            cows[sortcows[i].index].index=newco.cnt;
            pque.push(newco);
        }
        pque.push(co);
    }
    cout << time << endl;
    for(int i=0; i<n; i++) printf("%d\n", cows[i].index);

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
