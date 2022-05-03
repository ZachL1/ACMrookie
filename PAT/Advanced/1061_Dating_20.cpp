//
//  1061_Dating.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/2 11:01 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string day_map[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    vector<string> str(4);
    for (string &s : str){
        cin >> s;
    }
    
    size_t i = 0;
    int hh = -1, mm = -1;
    string day;
    while (i < str[0].size() && i < str[1].size()){
        char c = str[0][i];
        if (str[0][i] == str[1][i]){
            if (day.empty()){
                // :warning: 严格按照题目意思，不要自以为是！！
                if ('A'<=c && c<='G') day = day_map[c-'A'];
                ++i;
                continue;
            }
            // :warning: 严格按照题目意思，不要自以为是！！
            else if (('0'<=c&&c<='9') || ('A'<=c&&c<='N')){
                hh = isdigit(c) ? c-'0' : c-'A'+10;
                break;
            }
        }
        ++i;
    }
    i = 0;
    while (i < str[2].size() && i < str[3].size()){
        if (isalpha(str[2][i]) && str[2][i] == str[3][i]){
            mm = i;
            break;
        }
        ++i;
    }
    
    cout << day;
    printf(" %02d:%02d", hh, mm);
    return 0;
}
