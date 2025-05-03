#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s, chars;
    cin >> s >> chars;
    vector<int> vals(chars.size());
    for (int& x : vals) cin >> x;
    cout << maximumCostSubstring(s, chars, vals) << endl;
    return 0;
}

// https://leetcode.cn/problems/find-the-substring-with-maximum-cost    1422