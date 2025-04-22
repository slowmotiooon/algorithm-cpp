#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stones(n);
    for (int& x : stones) cin >> x;

    cout << lastStoneWeight(stones) << endl;
    return 0;
}

// https://leetcode.cn/problems/last-stone-weight   1173