//
//  1082_Read_Number_in_Chinese_25.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/3 8:16 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string n2c_map[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

bool is0(string str){
    // 判断 str 是否全为0
    return count(str.begin(), str.end(), '0') == str.size();
}
void num2c(string str){
    // 把一个小于一万的数用拼音表示
    
    if (str.empty()) return;
    if (str.front() == '0' && !is0(str)) cout << "ling ";
    
    int n = stoi(str);
    if (n<10){
        cout << n2c_map[n];
    } else if (n<100){
        cout << n2c_map[n/10] << " Shi";
        if (n %= 10) {
            cout << " ";
            num2c(to_string(n));
        }
    } else if (n<1000){
        cout << n2c_map[n/100] << " Bai";
        if (n %= 100){
            cout << " ";
            num2c(to_string(n));
        }
    } else{
        cout << n2c_map[n/1000] << " Qian";
        if (n %= 1000){
            cout << " ";
            num2c(to_string(n));
        }
    }
}

int main() {
    string s;
    cin >> s;
    
    if (s.front() == '-'){
        cout << "Fu ";
        s = s.substr(1);
    }
    int first = s.size()%4;
    if (first == 0) first = 4;
    if (s.size() > 8) {
        num2c(s.substr(0, first));
        cout << " Yi";
        if (!is0(s.substr(first, 4))) {
            cout << " ";
            num2c(s.substr(first, 4));
            cout << " Wan";
        } else if (!is0(s.substr(first+4))) cout << " ling";
        if (!is0(s.substr(first+4))){
            cout << " ";
            num2c(s.substr(first+4));
        }
    } else if (s.size() > 4){
        num2c(s.substr(0, first));
        cout << " Wan";
        if (!is0(s.substr(first, 4))) cout << " ";
        num2c(s.substr(first, 4));
    } else{
        num2c(s);
    }
    cout << endl;
    
    return 0;
}
