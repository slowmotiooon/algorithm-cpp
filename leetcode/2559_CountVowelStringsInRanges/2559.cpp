#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> words(n);
    vector<vector<int>> queries(k, vector<int>(2));
    for (string& s : words) cin >> s;
    for (vector<int>& x : queries) cin >> x[0] >> x[1];

    vector<int> ans = vowelStrings(words, queries);
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// https://leetcode.cn/problems/count-vowel-strings-in-ranges       1435