//
//  MaximumSum_POJ2479.cpp
//  workspace
//
//  Created by 段志超20192902 on 2021/4/8.
//

#include <cstdio>
#include <iostream>

using namespace std;
const int maxn=5e4+5;
int a[maxn], dpl[maxn], dpr[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; ++i){
            scanf("%d", a+i);
        }
        
        // 正向dp，求左序列中i的最大子段和
        int sum=0, mmax=a[0];
        for(int i=0; i<n; ++i){
            mmax = max(mmax, sum+a[i]);
            dpl[i] = mmax;

            // 记录前i项和，如果小于0则对后续序列和无贡献，将其置0
            sum = max(sum+a[i], 0);
        }

        // 逆向dp，求右序列中i的最大子段和
        sum = 0; mmax = a[n-1];
        for(int i=n-1; i>=0; --i){
            mmax = max(mmax, sum+a[i]);
            dpr[i] = mmax;

            sum = max(sum+a[i], 0);
        }
//        dpl[0]=a[0];
//        for(int i=1; i<n; ++i){
//            dpl[i]=max(dpl[i-1]+a[i], a[i]);
//        }
//        for(int i=1; i<n; ++i){
//            dpl[i]=max(dpl[i], dpl[i-1]);
//        }
//
//        dpr[n-1]=a[n-1];
//        for(int i=n-2; i>=0; --i){
//            dpr[i]=max(dpr[i+1]+a[i], a[i]);
//        }
//        for(int i=n-2; i>=0; --i){
//            dpr[i]=max(dpr[i], dpr[i+1]);
//        }
        
        int lef,rig,da=dpl[0]+dpr[1];
        for(int i=2; i<n; ++i){
            lef = dpl[i-1]; // [0,i)序列的最大子段和
            rig = dpr[i]; // [i,n)序列的最大子段和
            da = max(da, lef+rig);
        }
        cout << da << endl;
    }
    return 0;
}
