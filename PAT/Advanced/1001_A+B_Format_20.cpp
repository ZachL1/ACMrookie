//
//  1001_A+B_Format.cpp
//  workspace
//
//  Created by PDP11 on 2022/5/1.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    string s(to_string(a+b));
    int cnt = s.size()%3;
    if (cnt == 0 || (cnt == 1 && a+b<0)) cnt += 3;
    for(auto c : s){
        if (cnt == 0) {
            cnt =3;
            putchar(',');
        }
        --cnt;
        putchar(c);
    }
    putchar('\n');
        
    return 0;
}
