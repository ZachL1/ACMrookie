//
//  1108_Finding_Average_20.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/4 4:28 PM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 柳神的写法，使用 sscanf 和 ssprintf ，更精炼
/*
int n, cnt = 0;
char a[50], b[50];
double temp = 0.0, sum = 0.0;
cin >> n;
for(int i = 0; i < n; i++) {
    scanf("%s", a);
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f",temp);
    int flag = 0;
    for(int j = 0; j < strlen(a); j++)
        if(a[j] != b[j]) flag = 1;
    if(flag || temp < -1000 || temp > 1000) {
        printf("ERROR: %s is not a legal number\n", a);
        continue;
    } else {
        sum += temp;
        cnt++;
    }
}
*/


bool islegal(string num, double &n){
    // :warning: 要考虑带小数，所以应该是 8 而不是5
    // 启示：这里的目的是为了防止 stod 超出 double 的范围，但不应该用边界 5 来限定！！
    // 应该适当大一些，可以避免不必要的错误。
    // if (num.size() > 5) return false; 错误的！！！
    if (num.size() > 8) return false; // 其实这里不要也可以
    if (num.find('.') != string::npos && num.size()-num.find('.')-1 > 2) return false;
    
    n = 999999;
    try {
        n = stod(num);
    } catch (std::invalid_argument e) {
        return false;
    }
    if (n<-1000 || 1000<n) return false;
    if (to_string(n).substr(0, num.size()) != num) return false;
    
    return true;
}

int main(){
    int N;
    cin >> N;
    double sum = 0, curr;
    int cnt = 0;
    string curr_s;
    
    while (N--){
        cin >> curr_s;
        if (islegal(curr_s, curr)){
            sum += curr;
            cnt += 1;
        } else {
            cout << "ERROR: " << curr_s << " is not a legal number" << endl;
        }
    }
    
    if (cnt == 0) cout << "The average of 0 numbers is Undefined\n";
    else printf("The average of %d number%s is %.2f\n", cnt, (cnt == 1 ? "" : "s"), sum/cnt);
    
    return 0;
}
