#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    vector<string> ans;
    int n;cin>>n;
    string line, temp;
    while(n--){
        ans.clear();
        ans.pushback("AI: ");
        getline(cin, line);
        cout << line << endl;
        
        stringstream sin(line);
        while(sin>>temp){
            
        }
    }
}
