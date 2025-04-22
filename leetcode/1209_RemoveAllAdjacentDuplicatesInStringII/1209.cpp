#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << removeDuplicates(s, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii 1542