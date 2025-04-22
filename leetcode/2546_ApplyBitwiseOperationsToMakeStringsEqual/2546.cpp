#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s, target;
    cin >> s >> target;

    cout << makeStringsEqual(s, target) << endl;
    return 0;
}

// https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal/description/     1605