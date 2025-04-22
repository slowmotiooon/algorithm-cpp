#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> ans = validStrings(n);
    for (string s : ans) cout << s << endl;
    return 0;
}

// https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/description/     1353