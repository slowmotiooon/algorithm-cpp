#include "solution3.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    vector<int> result = findThePrefixCommonArray(A, B);
    for (int x : result) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/description/     1304