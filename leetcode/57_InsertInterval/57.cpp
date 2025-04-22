#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (auto& x : intervals) cin >> x[0] >> x[1];

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans = insert(intervals, newInterval);
    for (auto& x : ans) cout << x[0] << x[1] << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/insert-interval