#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<vector<int>> shifts(n, vector<int>(3));
    for (auto& x : shifts) cin >> x[0] >> x[1] >> x[2];

    cout << shiftingLetters(s, shifts) << endl;
    return 0;
}

// https://leetcode.cn/problems/shifting-letters-ii     1793