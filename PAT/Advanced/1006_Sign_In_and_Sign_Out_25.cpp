//
//  1006_Sign_In_and_Sign_Out_25.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/5 10:44 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct record{
    string id, signin, signout;
};
istream& operator>>(istream& is, record& r){
    return is >> r.id >> r.signin >> r.signout;
}

int main(){
    record unlock, lock, temp;
    int M;
    cin >> M;
    while (M--) {
        cin >> temp;
        if (unlock.id.empty() || temp.signin < unlock.signin) unlock = temp;
        if (lock.id.empty() || lock.signout < temp.signout) lock = temp;
    }
    
    cout << unlock.id << " " << lock.id << endl;
    
    return 0;
}
