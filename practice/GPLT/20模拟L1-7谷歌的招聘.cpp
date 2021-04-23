#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrimer(string s){
    long long n=stoll(s);
    
    if(n<4) return n>1;
    if(n%6!=1 && n%6!=5) return false;
    // 如果在6的倍数的两边也有可能不是
    for(int i=5; i<=sqrt(n); i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
int main(){
/*    string s="123456789";
    cout << s.substr(0,4);*/
    string s;
    int n,k;
    cin>>n>>k;getchar();
    getline(cin, s);
    if(s.length() < k){
        cout << 404 << endl;
        return 0;
    }
    int i=0;
    for(; i<=s.length()-k; ++i){
        if(isPrimer(s.substr(i,k))){
            cout << s.substr(i,k) << endl;
            break;
        }
    }
    if(i>s.length()-k) cout << 404 << endl;
    return 0;
}