/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start

/*
Boyer-Moore 投票算法

思路
如果我们把众数记为 +1+1，把其他数记为 -1−1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。

算法
Boyer-Moore 算法的本质和方法四中的分治十分类似。我们首先给出 Boyer-Moore 算法的详细步骤：

1. 我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；

2. 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：

    - 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
    - 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
    - 即对冲消耗的思想

在遍历完成后，candidate 即为整个数组的众数。
*/

#include <unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {

/*
        // 哈希表
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int num : nums) {
            ++hash[num];
            if (hash[num] > n/2) return num;
        }
        return -1;
*/

        // Boyer-Moore 投票算法 （摩尔对冲）
        int candidate = nums[0], count = 0;
        for (int num : nums) {
            if (!count) candidate = num;
            if (candidate == num) ++count;
            else --count;
        }

        return candidate;
    }
};
// @lc code=end

