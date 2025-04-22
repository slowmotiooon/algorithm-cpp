#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> parent = { -1, 0, 0, 1, 1, 1 };
    string s = "abaabc";
    vector<int> ans = findSubtreeSizes(parent, s);
    for (int x : ans) cout << x << ' ';
    return 0;
}