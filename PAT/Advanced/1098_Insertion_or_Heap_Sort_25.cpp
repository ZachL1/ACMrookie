//
//  1098_Insertion_or_Heap_Sort_25.cpp
//  ACMrookie
//
//  Created by zachduan on 2022/7/19.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace::std;

bool cmp(vector<int>::iterator l, vector<int>::iterator r, size_t n) {
    while (n--) {
        if (*l != *r) return false;
        ++l;
        ++r;
    }
    return true;
}

void print(vector<int>::iterator begin, size_t n) {
    while (n--) {
        cout << *begin;
        if (n) cout << " ";
        ++begin;
    }
}

int main(){
    int N;
    cin >> N;
    
    // 使用堆排序来模拟
    vector<int> init(N), sorted(N);
    for (auto &i : init) cin >> i;
    for (auto &s : sorted) cin >> s;
    
    bool isInsert = false;
    vector<int> insert_sorted(init);
    for (int i = 1; i < N; ++i) {
        int j = i;
        while (j >= 1 && insert_sorted[j] < insert_sorted[j-1] ){
            swap(insert_sorted[j], insert_sorted[j-1]);
            --j;
        }
        if (isInsert) break;
        if (cmp(sorted.begin(), insert_sorted.begin(), N)) isInsert = true;
    }
    if (isInsert) {
        cout << "Insertion Sort" << endl;
        print(insert_sorted.begin(), N);
    }
    else {
        cout << "Heap Sort" << endl;
        int index = N - 1;
        while (sorted[index] >= sorted[0]) --index;
        swap(sorted[0], sorted[index]);
        
        // 往下调整
        for (int i = 0; i*2+1 < index;) {
            int l = i*2+1, r = i*2+2;
            if (r < index && sorted[r] > sorted[l]) {
                l = r;
            }
            swap(sorted[i], sorted[l]);
            i = l;
        }
        print(sorted.begin(), N);
    }
    cout << endl;
    return 0;
}
