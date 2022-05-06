//
//  1025_PAT_Ranking_25.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/6 10:02 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
// The output must be sorted in nondecreasing order of the final ranks.
// 稳定排序如何实现 stable_sort
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct testee{
    ll number;
    int score, location;
    int rank[2] = {0}; // rank[0] 为 local_rank， rank[1] 为 final_rank
    testee(ll n, int s, int l)
        : number(n), score(s), location(l) {}
};

void generate_rank(vector<testee> &testees, int f) {
    // f = 1 则为 final_rank，0 则为 local_rank
    sort(testees.begin(), testees.end(),
         [](testee &l, testee &r){
            return l.score != r.score ? l.score > r.score : l.number < r.number ; });
    for (int i = 0; i < testees.size(); ++i) {
        if (i>0 && testees[i].score == testees[i-1].score)
            testees[i].rank[f] = testees[i-1].rank[f];
        else
            testees[i].rank[f] = i + 1;
    }
}

int main(){
    int N, K;
    cin >> N;

    vector<testee> all; // 所有的，和一个地区的
    for (int i = 1; i <= N; ++i) {
        vector<testee> loc;
        ll number; int score;

        cin >> K;
        while(K--){
            cin >> number >> score;
            loc.emplace_back(number, score, i);
        }
        generate_rank(loc, 0);
        // 批量移动？？？？
        all.insert(all.end(), loc.begin(), loc.end());
    }
    generate_rank(all, 1);
    cout << all.size() << endl;
    for (auto& t : all) {
        // :warning: 把字符串当做数字读入的时候，一定要当心前面可能含有前导0
        // 在输出的时候，使用格式控制进行补全
        printf("%013lld %d %d %d\n", t.number, t.rank[1], t.location, t.rank[0]);
    }
    return 0;
}
