//
//  1035_Password.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/1 8:57 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> names, passwords;
    string name, password;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> name >> password;
        bool flag = false;
        for (auto& c : password){
            // 可以使用 switch-case 代替
            if (c == '1'){
                c = '@';
                flag = true;
            }else if(c == '0'){
                c = '%';
                flag = true;
            }else if(c == 'l'){
                c = 'L';
                flag = true;
            }else if(c == 'O'){
                c = 'o';
                flag = true;
            }
        }
        if (flag) {
            names.push_back(name);
            passwords.push_back(password);
        }
    }
    
    if (names.empty()){
        if (N==1){
            cout << "There is " << N << " account and no account is modified" << endl;
        }
        else {
            cout << "There are " << N << " accounts and no account is modified" << endl;
        }
    }
    else {
        cout << names.size() << endl;
        for (int i = 0; i < names.size(); ++i){
            cout << names[i] << ' ' << passwords[i] << endl;
        }
    }
    
    return 0;
}
