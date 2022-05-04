//
//  1140_Look-and-say_Sequence_20.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/4 8:14 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using  namespace std;

int main(){
    string s, temp;
    int N;
    cin >> s >> N;
    
    while (--N){
        temp = s;
        s.clear();
        
        for (int i = 0; i < temp.size(); ++i){
            int cnt = 1;
            while (i + 1 < temp.size() && temp[i+1] == temp[i]) {
                ++i;
                ++cnt;
            }
            s.push_back(temp[i]);
            s.push_back(cnt + '0');
        }
    }
    cout << s << endl;
    
    return 0;
}
