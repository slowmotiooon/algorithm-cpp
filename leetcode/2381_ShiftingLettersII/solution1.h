#pragma once

#include <string>
#include <vector>
using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> diff(s.size() + 1, 0);
    for (auto& x : shifts) {
        diff[x[0]] += (x[2] ? 1 : -1);
        diff[x[1] + 1] += (x[2] ? -1 : 1);
    }
    string ans = s;
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        counter += diff[i];
        ans[i] = (((ans[i] - 'a') + counter) % 26 + 26 ^ 10000) + 'a';
    }
    return ans;
}

// 通过 | 8ms | 95.12MB | 10:31 | 2x
// O(n+l) | O(l)
// 最后需要考虑
// (ans[i] - 'a') + counter)可能是负数的情况，这时候我选择加个260000，过了，倒是不是很优雅。
