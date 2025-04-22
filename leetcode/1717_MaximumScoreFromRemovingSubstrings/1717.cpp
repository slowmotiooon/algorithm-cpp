#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    cout << maximumGain(s, x, y) << endl;
    return 0;
}

// https://leetcode.cn/problems/maximum-score-from-removing-substrings 1868