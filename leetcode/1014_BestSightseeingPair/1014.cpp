#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int& x : values) cin >> x;

    cout << maxScoreSightseeingPair(values) << endl;
    return 0;
}

// https://leetcode.cn/problems/best-sightseeing-pair/description/      1730