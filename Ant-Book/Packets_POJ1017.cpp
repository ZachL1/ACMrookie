//
//  Packets_POJ1017.cpp
//  workspace
//
//  Created by PDP11 on 2021/3/27.

//  题解：从面积大的开始取，一块6*6的板子可以去一块5*5的板子剩下11个
//  1*1的板子。取一块4*4的板子剩下5个2*2的板子。
//  6*6的板子可以取四块3*3的板子，在一块6*6板子上取3*3的板子数目为  1  2  3
//  4  的时候剩下 2*2的板子分别为  5  3  1
//  0，剩余部分还可以去1*1的板子。 若2*2的板子有剩余，还可以分割成1*1的板子。

//  原文链接：https://blog.csdn.net/zwj1452267376/article/details/50428543

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    int size[7];
    while(true){
        bool end=true;
        for(int i=1; i<7; i++)
            if(scanf("%d", size+i)!=EOF && size[i]!=0) end=false;
        if(end) break;
        
        int ans=size[6]+size[5]+size[4]+(size[3]+3)/4;//计算边长为3 4 5 6的板子消耗量
        
        int two[4]={0,5,3,1};
        int cnt_2=size[4]*5+two[size[3]%4];
        if(cnt_2<size[2]){
            ans+=(size[2]-cnt_2+8)/9;//当上面剩余的2*2板子量不足时，需要消耗新的板子
        }
        
        // 1*1的板子补上前面的空缺，由于1*1的板子的面积是1，
        // 故用总面积减去2、3、4、5、6板子的面积就是1*1的板子数
        int cnt_1=(ans-size[6])*36-size[5]*25-size[4]*16-size[3]*9-size[2]*4;
        if(cnt_1<size[1]) ans+=(size[1]-cnt_1+35)/36;//当上面剩余的1*1板子量不足时，需要消耗新的板子
        
        cout << ans << endl;
    }
#ifdef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
