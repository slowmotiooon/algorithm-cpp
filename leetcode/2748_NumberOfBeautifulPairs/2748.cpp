#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << countBeautifulPairs(nums) << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-beautiful-pairs/description/      1301