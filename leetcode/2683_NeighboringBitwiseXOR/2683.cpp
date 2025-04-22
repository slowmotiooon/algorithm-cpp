#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> derived(n);
    for (int& x : derived) cin >> x;

    cout << doesValidArrayExist(derived) << endl;
    return 0;
}

// https://leetcode.cn/problems/neighboring-bitwise-xor/description/        1518