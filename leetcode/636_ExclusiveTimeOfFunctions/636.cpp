#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> logs(k);
    for (string& x : logs) cin >> x;

    vector<int> result = exclusiveTime(n, logs);
    for (int x : result) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/exclusive-time-of-functions