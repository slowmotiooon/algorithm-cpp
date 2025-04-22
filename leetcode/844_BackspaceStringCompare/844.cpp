#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    cout << backspaceCompare(s, t) << endl;
    return 0;
}

// https://leetcode.cn/problems/backspace-string-compare        1228