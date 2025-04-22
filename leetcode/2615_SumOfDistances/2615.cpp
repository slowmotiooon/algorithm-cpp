#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    vector<long long> result = distance(nums);
    for (auto x : result) cout << x << ' ';
    cout << endl;
    return 0;
}

//  https://leetcode.cn/problems/sum-of-distances       1793