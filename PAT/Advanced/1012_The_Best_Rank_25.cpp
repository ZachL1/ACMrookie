//
//  1012_The_Best_Rank.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/5 11:26 AM. 35
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

// 这道题很坑！
// 在算平均分时需要四舍五入到整数，然后在排名时要处理并列排名！
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

struct stu{
    int id;
    int score[4];
    int rank[4];
};
istream& operator>> (istream& is, stu& s){
    is >> s.id >> s.score[1] >> s.score[2] >> s.score[3];
    // :warning: 四舍五入！！！
    s.score[0] = round((s.score[1] + s.score[2] + s.score[3])/3.0);
    return is;
}
ostream& operator<< (ostream& os, const stu& s){
    int best_rank = 0;
    for (int i = 1; i < 4; ++i){
        if (s.rank[i] < s.rank[best_rank]) best_rank = i;
    }
    char kind[] = {'A', 'C', 'M', 'E'};
    return os << s.rank[best_rank] << " " << kind[best_rank];
}

void score2rank(vector<stu>& stus, int score_kind){
    // 将分数转换为排名
    int i = score_kind;
    sort(stus.begin(), stus.end(), [i](stu l, stu r){ return l.score[i] > r.score[i]; });
    for (int j = 0; j < stus.size(); ++j){
        // :warning: 排名时，处理并列排名！！
        if (j > 0 && stus[j].score[i] == stus[j-1].score[i]) stus[j].rank[i] = stus[j-1].rank[i];
        else stus[j].rank[i] = j + 1;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<stu> stus;
    stu temp;
    while (N--) {
        cin >> temp;
        stus.push_back(temp);
    }
    // sort可以用于关联容器吗？？？
    // 平均分的排名
    score2rank(stus, 0);
    // c 语言排名
    score2rank(stus, 1);
    // 数学排名
    score2rank(stus, 2);
    // 英语排名
    score2rank(stus, 3);
    
    unordered_map<int, stu> stu_map;
    for (auto &s : stus){
        stu_map[s.id] = s;
    }
    
    while (M--){
        int temp_id;
        cin >> temp_id;
        // map 查看是否存在
        if (stu_map.find(temp_id) != stu_map.end()) cout << stu_map.at(temp_id) << endl;
        else cout << "N/A\n";
    }
    
    return 0;
}
