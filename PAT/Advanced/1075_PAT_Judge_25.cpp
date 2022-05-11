//
//  1075_PAT_Judge.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/9 3:51 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

struct user{
    int id = 0, total = 0, perfect = 0, rank;
    int score[6] = {-1, -1, -1, -1, -1, -1};
    bool out = false;
};

bool cmp(user l, user r){
    if (l.total != r.total) return l.total > r.total;
    if (l.perfect != r.perfect) return l.perfect > r.perfect;
    // :warning: 注意提交且编译通过了的也有可能为0分，因此有可能把他排到没有提交过的人的后面，这导致他排名变低了！！！
    if (l.out != r.out) return l.out > r.out;
    return l.id < r.id;
}

int main(){
    int N, K, M;
    int perfect_s[6] = {0};
    cin >> N >> K >> M;
    for (int i = 1; i <= K; ++i) cin >> perfect_s[i];
    
    vector<user> users(N+1);
    int id, p, score;
    while (M--){
        cin >> id >> p >> score;
        user &curr = users[id]; // 当前用户
        
        if (score == -1) score = 0;
        else curr.out = true;
        if (users[id].id == 0) curr.id = id; // 尚未添加该用户
        if (score <= curr.score[p]) continue; // 不需要更新
        
        curr.total += curr.score[p] == -1 ? score : score - curr.score[p];
        // :warning: 注意满分重复通过的情况！！！
        curr.perfect += score == perfect_s[p];
        curr.score[p] = score;
    }
    sort(users.begin()+1, users.end(), cmp);
    
    for (int i = 1; i < users.size(); ++i){
        user &curr = users[i]; // 当前用户
        if (!curr.out) continue;
        
        curr.rank = i;
        if (i > 1 && curr.total == users[i-1].total) curr.rank = users[i-1].rank;
        printf("%d %05d %d ", curr.rank, curr.id, curr.total);
        for (int j = 1; j <= K; ++j){
            if (j != 1) putchar(' ');
            if (curr.score[j] == -1) printf("-");
            else printf("%d", curr.score[j]);
        }
        cout << endl;
    }
    return 0;
}
