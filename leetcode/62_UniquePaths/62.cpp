#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    Solution* s = new Solution();
    cout << s->uniquePaths(m, n) << endl;
    return 0;
}

// https://leetcode.cn/problems/unique-paths
