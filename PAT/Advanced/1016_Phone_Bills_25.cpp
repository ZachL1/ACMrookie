//
//  1016_Phone_Bills_25.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/5 3:13 PM. 45
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

// chronologically
// guaranteed
// assume that
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

double toll[25];
struct record{
    string date, word;
    record(string& d, string& w) : date(d), word(w) {}
};
//istream& operator>> (istream& is, record& r){
//    return is >> r.date >> r.word;
//}

void compute(string& on, string& off, int& l, double& c){
    int on_d = stoi(on.substr(3,2)), off_d = stoi(off.substr(3,2)),
        on_h = stoi(on.substr(6,2)), off_h = stoi(off.substr(6,2)),
        on_m = stoi(on.substr(9,2)), off_m = stoi(off.substr(9,2));
    
    c = 0;
    l = (off_d - on_d) * 24 * 60 + (off_h - on_h) * 60 + off_m - on_m;
    // :+1: 计算从 00:00:00 到目前的费用
    c += off_d * 60 * toll[24] + off_m * toll[off_h];
    for (int i = 0; i < off_h; ++i) c += 60 * toll[i];
    c -= on_d * 60 * toll[24] + on_m * toll[on_h];
    for (int i = 0; i < on_h; ++i) c -= 60 * toll[i];
    c /= 100;
}

int main(){
    for (int i = 0; i < 24; ++i) {
        cin >> toll[i];
        toll[24] += toll[i];
    }
    int N; cin >> N;
    
    map<string, vector<record>> customers;
    while (N--){
        string name, date, word;
        cin >> name >> date >> word;
        customers[name].emplace_back(date, word);
//        string name;
//        record temp;
//        cin >> name >> temp;
//        customers[name].push_back(temp);
    }
    
    for (auto& c : customers){
        vector<record> &records = c.second;
        bool outed = false; // 是否已经输出消费者编号
        
        sort(records.begin(), records.end(), [](record& l, record& r){ return l.date < r.date; });
        double sum = 0, charge = 0;
        int lasting = 0;
        string online_time;
        for (auto& r : records){
            if (!online_time.empty() && r.word == "off-line") {
                compute(online_time, r.date, lasting, charge);
                sum += charge;
                // :warning: 只有消费不为 0 时才产生账单！
                if (sum != 0){
                    if(!outed) {
                        cout << c.first << " " << records.front().date.substr(0, 2) << endl;
                        outed = true;
                    }
                    cout << online_time.substr(3) << " " << r.date.substr(3);
                    printf(" %d $%.2f\n", lasting, charge);
                }
                // :warning: 记得清空上线时间！！！
                online_time.clear();
            } else if(r.word == "on-line"){
                online_time = r.date;
            }
        }
        if(sum != 0) printf("Total amount: $%.2f\n", sum);
    }
    return 0;
}
