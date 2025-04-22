#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (auto& s : tokens) cin >> s;
    cout << evalRPN(tokens) << endl;
    return 0;
}

// https://leetcode.cn/problems/evaluate-reverse-polish-notation