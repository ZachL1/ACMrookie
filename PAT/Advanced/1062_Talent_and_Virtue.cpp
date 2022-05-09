//
//  1062_Talent_and_Virtue.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/9 2:24 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, L, H;
enum theory{sage, nobleman, fool, small};

struct people{
    string id;
    int virtue, talent, total;
    theory kind;
};
istream& operator>> (istream& is, people& p){
    is >> p.id >> p.virtue >> p.talent;
    p.total = p.virtue + p.talent;
    
    if (p.virtue >= H && p.talent >= H) p.kind = sage;
    else if (p.virtue >= H) p.kind = nobleman;
//    else if (p.talent < H && p.virtue < H && p.talent <= p.virtue) p.kind = fool;
    else if (p.talent < H && p.talent <= p.virtue) p.kind = fool;
    else p.kind = small;
    
    return is;
}

bool cmp(people l, people r){
    if (l.kind != r.kind) return l.kind < r.kind;
    else if (l.total != r.total) return l.total > r.total;
    else if (l.virtue != r.virtue) return l.virtue > r.virtue;
    return l.id < r.id;
}
int main(){
    cin >> N >> L >> H;
    
    vector<people> peoples;
    people temp;
    while (N--){
        cin >> temp;
        if (temp.virtue >= L && temp.talent >= L) peoples.push_back(temp);
    }
    sort(peoples.begin(), peoples.end(), cmp);
    
    cout << peoples.size() << endl;
    for (int i = 0; i < peoples.size(); ++i){
        if (i) putchar('\n');
        cout << peoples[i].id << " " << peoples[i].virtue << " " << peoples[i].talent;
    }
    return 0;
}
