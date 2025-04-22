#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (string& s : grid) cin >> s;

    cout << largestArea(grid) << endl;
    return 0;
}

// https://leetcode.cn/problems/YesdPw/description/
