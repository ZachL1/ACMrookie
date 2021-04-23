#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    bitset<32> bin;
    
    char bit;
    for(int i=0; i<m; ++i){
        bin.reset();getchar();
        for(int j=0; j<n; ++j){
            bit=getchar();
            if(bit=='n') bin.set(n-j-1);
        }
        cout << bin.to_ulong() + 1 << endl;
    }
    return 0;
}