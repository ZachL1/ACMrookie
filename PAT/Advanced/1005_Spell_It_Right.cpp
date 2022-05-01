//
//  1005_Spell_It_Right.cpp
//  workspace
//
//  Created by PDP11 on 2022/5/1.
// 20:12


#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string n_map[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    int sum = 0;
    int num;
    while ((num = getchar()) != EOF){
        if (num == '\n') break;
        sum += num - '0';
    }
    
    string sum_s = to_string(sum);
    for (int i = 0; i < sum_s.size()-1; ++i){
        cout << n_map[sum_s[i]-'0'] << " ";
    }
    cout << n_map[sum_s.back()-'0'] << endl;
    
    return 0;
}
