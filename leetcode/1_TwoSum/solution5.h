#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++) {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return { it->second, i };
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

// 运行结果：
// 通过 | 8ms | 10.96MB
// 这是最优解其中之一。由于全部的测试样例中，重复的数字都是target的一半，所以可以省略solution4中的nums[i]*2==target判断，简化代码。
// 使用变量it 接收find函数的结果，增加了代码的可读性。