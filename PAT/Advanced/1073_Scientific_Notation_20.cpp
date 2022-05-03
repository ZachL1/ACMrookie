//
//  1073_Scientific_Notation.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/2 11:06 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    char sign;
    sign = getchar();
    if (sign == '-') putchar(sign);
    
    string sci;
    cin >> sci;
    
//    double conv = stod(sci);
    int index_of_dot = sci.find('.');
    int index_of_e = sci.find('E');
    
    int exp = stoi(sci.substr(index_of_e+1)); // 指数部分
    string real = sci.substr(0, index_of_e);
    
    if (exp < 0){
        real.insert(index_of_dot+1, -exp, '0'); // 小数点后移相应的位数
        swap(real[0], real[-exp+1]); // 把原来的整数部分换回正确的位置
    } else {
        for (int dot = index_of_dot; exp--; ++dot){
            if (dot >= real.size()) real.push_back('0'); // dot必须每轮递增，因为 real.size() 是变化的
            else if (dot+1 == real.size()) real[dot] = '0';
            else swap(real[dot], real[dot+1]);
        }
    }
    if (real.back() == '.')
        real.pop_back(); // 处理特殊情况：-1.2E+1 -> 12.
    cout << real << endl;
    
    return 0;
}
