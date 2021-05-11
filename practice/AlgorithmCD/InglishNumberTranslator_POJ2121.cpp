//
//  InglishNumberTranslator_POJ2121.cpp
//  workspace
//
//  Created by 段志超20192902 on 2021/5/11.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
string ww[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(){
    vector<string> w;
    for(int i=0; i<28; ++i) w.push_back(ww[i]);
    map<string, int> mapw;
    for(int i=0; i<w.size(); ++i){
        mapw.insert(make_pair(w[i], i<20 ? i : ((i-20+2)*10)));
    }
    map<string, int> mapl;
    mapl.insert(make_pair("hundred", 100));
    mapl.insert(make_pair("thousand", 1000));
    mapl.insert(make_pair("million", 1000000));
    
    string s;
    vector<string> tmpw;
    while(cin>>s){
        tmpw.clear();
        tmpw.push_back(s);
        while(getchar() != '\n'){
            cin>>s; tmpw.push_back(s);
        }
        long long ans=0, i=0, tmpi=0;
        if(tmpw[0]=="negative") {cout<<"-"; ++i;}
        for(; i<tmpw.size(); ++i){
            if(mapw.find(tmpw[i]) != mapw.end()){
                tmpi+=mapw[tmpw[i]];
            }
            if(mapl.find(tmpw[i]) != mapl.end()){
                tmpi*=mapl[tmpw[i]];
                if(mapl[tmpw[i]]>100){
                    ans+=tmpi;
                    tmpi=0;
                }
            }
        }
        ans+=tmpi;
        cout << ans << endl;
    }
    return 0;
}
