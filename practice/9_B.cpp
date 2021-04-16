#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
const int maxn=8;
int num[maxn];

void solve(int n){
    unsigned long num;
    if(n<0) num = ~n;
    else num=n;
    bitset<8> twon(num);
    if(n<0) twon.flip();

    for(int i=(int)twon.size(); i>=0; --i){
        if(twon[i]) cout << '.';
        else cout << ' ';
    }
}
int main(){
//    vector<int> v;
    int temp, i=0;
    while(~scanf("%d", &temp)){
        solve(temp);
        if((++i % 2) == 0) cout << endl;
    }
    printf("%f\n",pow(9,9));
    return 0;
}
