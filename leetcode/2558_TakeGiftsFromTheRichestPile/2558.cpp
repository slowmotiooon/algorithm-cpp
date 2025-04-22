#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> g(n);
    for (int& x : g) cin >> x;
    cin >> k;
    cout << pickGifts(g, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/take-gifts-from-the-richest-pile 1277