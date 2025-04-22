#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    cout << countTriplets(arr) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/