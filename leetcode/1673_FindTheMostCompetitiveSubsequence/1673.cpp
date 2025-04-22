#include "solution1.h"
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    int k;
    cin >> k;

    vector<int> result = mostCompetitive(nums, k);
    for (int i : result) cout << i << ' ';
    cout << endl;
    return 0;
}

int fun()
{
    int i = 1;
    return i;
}

// https://leetcode.cn/problems/find-the-most-competitive-subsequence/description/
// 1802
