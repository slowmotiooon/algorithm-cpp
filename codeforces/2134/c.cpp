#include <iostream>
#include <vector>
using namespace std;

long long calc(vector<int> nums) {
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n - 1; i += 2) {
        int diff = nums[i + 1] - nums[i];
        if (diff < 0) {
            nums[i] += diff;
            ans -= diff;
        }
        if (i + 2 < n) {
            int diff = nums[i + 1] - nums[i] - nums[i + 2];
            if (diff < 0) {
                nums[i + 2] += diff;
                ans -= diff;
            }
        }
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    vector<vector<int>> list(k);
    for (vector<int>& nums : list) {
        int n;
        cin >> n;
        nums.resize(n);
        for (int& x : nums) cin >> x;
    }
    for (vector<int> nums : list) { cout << calc(nums) << endl; }
    return 0;
}

// accepted 359ms 0kb