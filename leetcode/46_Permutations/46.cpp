#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    vector<vector<int>> res = permute(nums);
    for (auto l : res) {
        for (auto x : l) cout << x;
        cout << endl;
    }
    return 0;
}