#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    cout << numOfSubarrays(arr) << endl;
    return 0;
}

// https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum       1611