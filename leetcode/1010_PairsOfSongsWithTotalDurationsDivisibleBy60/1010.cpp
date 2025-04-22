#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> time(n);
    for (int& x : time) cin >> x;

    cout << numPairsDivisibleBy60(time) << endl;
    return 0;
}

// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
// 1377