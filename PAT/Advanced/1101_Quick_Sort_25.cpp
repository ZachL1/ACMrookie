//
//  1101_Quick_Sort_25.cpp
//  ACMrookie
//
//  Created by zachduan on 2022/7/20.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace::std;

int main(){
    int N;
    cin >> N;
    
    vector<size_t> nums(N);
    size_t left_max = 0, right_min = 1e9 + 1;
    unordered_set<size_t> left, right;
    for (auto& n : nums) {
        cin >> n;
        if (n >= left_max) left.insert(n);
        left_max = max(left_max, n);
    }
    
    for (int i = nums.size()-1; i >= 0; --i) {
        if (nums[i] <= right_min) right.insert(nums[i]);
        right_min = min(right_min, nums[i]);
    }
    
    vector<size_t> ans;
    for (auto l : left) {
        if (right.find(l) != right.end()) ans.push_back(l);
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i+1 != ans.size()) cout << " ";
    }
    cout << endl;
    
    return 0;
}
