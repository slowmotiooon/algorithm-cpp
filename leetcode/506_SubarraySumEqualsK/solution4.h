#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int ans = 0, s = 0;
    unordered_map<int, int> cnt{ {0, 1} }; // s[0]=0 单独统计
    for (int x : nums) {
        s += x;
        // 注意不要直接 += cnt[s-k]，如果 s-k 不存在，会插入 s-k
        ans += cnt.contains(s - k) ? cnt[s - k] : 0;
        cnt[s]++;
    }
    return ans;
}

// 运行结果： 通过
// O(n) | O(m) m指哈希表的元素数量 m<=n
// 题解：https://leetcode.cn/problems/subarray-sum-equals-k/solutions/2781031/qian-zhui-he-ha-xi-biao-cong-liang-ci-bi-4mwr
// 照搬题解，使用了前缀和和哈希表cnt。cnt中的contains函数为C++20中特有的函数。
