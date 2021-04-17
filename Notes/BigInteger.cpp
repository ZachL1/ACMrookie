//
//  BigInteger.cpp
//  workspace
//
//  Created by PDP11 on 2021/4/17.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
using LL = long long;

struct bigInt{
    const static int WIDTH=4; // 大整数每一位的宽度
    const static int BASE=1e4;// 大整数的“进制”，这里实际上是定义了10^8进制数
    vector<int> v;
    
    // 构造函数
    bigInt(){}
    bigInt(LL n){
        *this=n;
    }
    bigInt operator= (LL n){
        v.clear();
        do{
            v.push_back(n%BASE);
            n/=BASE;
        }while(n);
        return *this;
    }
    
    // 大整数加大整数
    bigInt operator+ (const bigInt& b) const {
        bigInt temp; temp.v.clear();
        for(int i=0, up=0; ; ++i){
            // 如果两个大整数都遍历完了，而且没有进位，则加法完成
            if(up==0 && i>=max(v.size(), b.v.size())) break;
            
            int he=up;
            if(i<v.size()) he+=v[i];
            if(i<b.v.size()) he+=b.v[i];
            temp.v.push_back(he%BASE);
            up=he/BASE;
        }
        return temp;
    }
    bigInt operator += (const bigInt& b) {
        *this = *this + b;
        return *this;
    }
    
    // 大整数乘小整数
    bigInt operator* (const int& b) const {
        bigInt temp; temp.v.clear();
        for(int i=0, up=0; ; ++i){
            // 和加法类似的思想，大整数每一位和小整数相乘，
            // 结果对BASE做除法，商作为进位，余数放在当前位。
            // 如果大整数便利完了，而且没有进位，则乘法完成
            if(up==0 && i>=v.size()) break;
            
            int ji=up;
            if(i<v.size()) ji += v[i]*b;
            temp.v.push_back(ji % BASE);
            up = ji/BASE;
        }
        return temp;
    }
    bigInt operator*= (const int& b){
        return *this = *this*b;
    }
};
// 输出大整数
ostream& operator<< (ostream& out, const bigInt& b){
    int i=b.v.size()-1;
    cout << b.v[i];
    while(--i>=0){
        printf("%0*d", bigInt::WIDTH, b.v[i]);
    }
    return out;
}

int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int temp; bigInt t=1;
    while(~scanf("%d", &temp)){
        t *= temp;
    }
    cout << t << endl;

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
