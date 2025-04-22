#pragma once

#include <vector>
using namespace std;

constexpr int max(int x, int y) { return x > y ? x : y; }

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int minSum = 0;

    vector<int> dp = { INT_MIN };

    // dp数组记录的是截至第i个元素的最大前缀和
    // dp的转移方程是 dp[i+1] = max(dp[i], sum-minSum);

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        dp.push_back(max(dp[i], sum - minSum));
        if (sum < minSum) minSum = sum;
    }

    return dp[nums.size()];
}

// 运行结果：
// 通过 | 84ms | 75.62MB
// O(n) | O(n)
// 思路来自：https://leetcode.cn/problems/maximum-subarray/solutions/2533977/qian-zhui-he-zuo-fa-ben-zhi-shi-mai-mai-abu71 方法二
// 运用了一维动态规划。
// 题解中有优化后的代码：

int betterMaxSubArray(vector<int>& nums) {
    int ans = INT_MIN; // 注意答案可以是负数，不能初始化成 0
    int f = 0;
    for (int x : nums) {
        f = max(f, 0) + x;  //相当于max(f+x,x)
        ans = max(ans, f);
    }
    return ans;
}

// 1. 改进了dp的转移函数，使得f可以计算当前最长前缀和。
// 因为f的更新只需要f[i-1]与0做比较，所以可以把f从dp数组变为变量，降低空间复杂度。
// 具体流程 样例： -2 1 -3 4 -1 2 1 -5 4
// 第一次循环：    |
// f记录为nums第一个元素（的和）。同时把最大前缀和ans更新为比INT_MIN更大的-2
// 第二次循环：       | 
// 因为-2+1比1小，f更新为1，同时把ans更新为1
// 第三次循环：         |
// 因为1-3比-3大，f更新为1-3=-2，因为-2<1，所以ans不变
// 第四次循环：           |
// 因为-2+4比4小，f更新为4，ans更新为4

//