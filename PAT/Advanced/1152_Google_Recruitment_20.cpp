//
//  1152_Google_Recruitment_20.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/4 8:38 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(string s){
    long long num = stoll(s);
    // 特殊情况
    if (num <= 3) return num > 1;
    // 不在 6 两侧的一定不是素数
    if (num%6 != 1 && num%6 != 5) return false;
    // 在 6 两侧的也有可能不是素数
    // 而在 6 两侧的数如果不是素数必然有一个在 6 两侧的因数
    for (long long i = 5; i <= sqrt(num); i+=6){
        if (num % i == 0 || num % (i+2) == 0) return false;
    }
    return true;
}

int main(){
    int L, K;
    string N;
    cin >> L >> K >> N;
    
    if (K==1){
        cout << N.front() << endl;
        return 0;
    }
    for (int i = 0; i < N.size()-K+1; ++i){
        if (isPrime(N.substr(i, K))){
            cout << N.substr(i, K) << endl;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}
