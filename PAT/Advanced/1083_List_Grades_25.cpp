//
//  main.cpp
//  ACMrookie
//
//  Created by zachduan on 2022/7/19.
// interval  boundaries  distinct  guaranteed

#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace::std;

struct interval {
    string name;
    string id;
    int grade;
    
    bool operator < (const interval& r) const{
        return this->grade > r.grade;
    }
};

int main(int argc, const char * argv[]) {
    int N;
    interval in;

    set<interval> ins;
    cin >> N;
    while (N--) {
        cin >> in.name >> in.id >> in.grade;
        ins.insert(in);
    }
    
    int bound1, bound2;
    bool flag = true;
    cin >> bound1 >> bound2;
    for (const auto& i : ins) {
        if (i.grade >= bound1 && i.grade <= bound2) {
            cout << i.name << " " << i.id << endl;
            flag = false;
        }
    }
    if (flag) cout << "NONE" << endl;
    
    
    return 0;
}
