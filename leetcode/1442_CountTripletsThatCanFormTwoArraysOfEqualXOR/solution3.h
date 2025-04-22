#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

int countTriplets(vector<int>& arr) {
    unordered_map<int, int> counter, sum;
    int xor_ = 0;
    int ans = 0;
    counter[0] = 1;
    sum[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
        xor_ ^= arr[i];
        if (counter.find(xor_) != counter.end()) {
            ans += (i - 1) * counter[xor_] - sum[xor_];
            counter[xor_]++;
            sum[xor_] += i;
        }
        else {
            counter[xor_] = 1;
            sum[xor_] = i;
        }
    }
    return ans;
}

// 通过 | 0ms | 10.13MB
// O(n) | O(1)
// 解释起来比较复杂。

// 例如：            2 3 1 6 7 1 3 3 1
// 索引：         -1 0 1 2 3 4 5 6 7 8 9
// 其前缀异或为：   0 2 1 0 6 1 0 3 0 1

// 如果 a^b^c=d^e，那么 a^b^c^d^e=0
// 如果 a^b^c=a^b^c^d^e^f^g，那么 d^e^f^g=0，即d,e,f,g可以组成4-1=3个合法的三元组。
// (d,efg; de,fg; def,g)
// 所以应该统计前缀异或相等的索引。 以0为例。前缀异或为1的索引为-1，2，5，7. 计算
// 从第二个开始 每个前缀异或为1的索引 与 第一个前缀异或为1的索引 形成的区间 的合法三元组 数量。
// 索引2: 2-(-1)-1                  =2      --> 2*1 -(-1)       -1*1
// 索引5: 5-(-1)-1 + 5-2-1          =7      --> 5*2 -((-1)+2)   -1*2
// 索引7: 7-(-1)-1 + 7-2-1 + 7-5-1  =12     --> 7*3 -((-1)+2+5) -1*3
// 经过加法运算律，可以总结为：
// 索引i处的合法三元组数量  = (i-1) * (当前xor_的数量-1) - (i之前的相等索引之和)
// 即位于16行的     ans  += (i-1) * counter[xor_]     - sum[xor_];
// 即可实现以O(1)时间复杂度计算索引i对应合法三元组数量