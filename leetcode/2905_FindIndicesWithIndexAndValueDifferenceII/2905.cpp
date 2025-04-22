#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    int indexDifference, valueDifference;
    cin >> indexDifference >> valueDifference;

    vector<int> ans = findIndices(nums, indexDifference, valueDifference);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/find-indices-with-index-and-value-difference-ii/description/ 1764