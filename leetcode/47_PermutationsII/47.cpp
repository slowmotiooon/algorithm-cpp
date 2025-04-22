#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto& x : nums) cin >> x;

    vector<vector<int>> result = permuteUnique(nums);
    for (auto& l : result) {
        for (auto& x : l) cout << x;
        cout << endl;
    }
    return 0;
}

// https://leetcode.cn/problems/permutations-ii?envType=daily-question&envId=2025-02-06