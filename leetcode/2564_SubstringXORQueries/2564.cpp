#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<vector<int>> queries(n, vector<int>(2));
    for (vector<int>& x : queries) cin >> x[0] >> x[1];
    vector<vector<int>> ans = substringXorQueries(s, queries);
    for (vector<int> x : ans) cout << x[0] << ' ' << x[1] << endl;
    return 0;
}

// https://leetcode.cn/problems/substring-xor-queries/description/      1959