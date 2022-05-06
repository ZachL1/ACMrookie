//
//  1028_List_Sorting.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/6 13:34 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

// 柳神的写法，通过全局变量 c 来实现不同种类的排序，并且在 cmp 函数中实现
// 这样的写法更简洁，我用 lambda 表达式反而复杂了 [笑]
/*
 int c;
 int cmp1(NODE a, NODE b) {
     if(c == 1) {
         return a.no < b.no;
     } else if(c == 2) {
         if(strcmp(a.name, b.name) == 0) return a.no < b.no;
         return strcmp(a.name, b.name) <= 0;
     } else {
         if(a.score == b.score) return a.no < b.no;
         return a.score <= b.score;
     }
 }
 */

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct record{
    string id_name[2];
    int grade;
};
istream& operator>> (istream& is, record& r){
    return is >> r.id_name[0] >> r.id_name[1] >> r.grade;
}
ostream& operator<< (ostream& os, record& r){
    return os << r.id_name[0] << " " << r.id_name[1] << " " << r.grade;
}

int main(){
    int N, C;
    cin >> N >> C;
    
    vector<record> records;
    record temp;
    while (N--) {
        cin >> temp;
        records.push_back(temp);
    }
    
    C -= 1;
    if (C == 2) {
        sort(records.begin(), records.end(), [](record& l, record& r)
             { return l.grade!=r.grade ? l.grade < r.grade : l.id_name[0] < r.id_name[0]; });
    } else {
        sort(records.begin(), records.end(),
             [C](record& l, record& r)
                { return l.id_name[C]!=r.id_name[C] ? l.id_name[C] < r.id_name[C] : l.id_name[0] < r.id_name[0]; });
    }
    for (auto& r : records) {
        cout << r << endl;
    }
    return 0;
}
