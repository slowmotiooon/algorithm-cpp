#include <iostream>
#include <vector>
using namespace std;

long long gcd(vector<long long> nums) {
    long long res = nums[0];
    for (auto x : nums) { res }
}

vector<long long> calc(vector<long long> nums, int k) {}

int main() {
    int total;
    cin >> total;

    vector<vector<long long>> list(total);
    vector<vector<long long>> results;
    for (vector<long long>& nums : list) {
        int n, k;
        cin >> n >> k;
        nums.resize(n);
        for (long long& x : nums) cin >> x;
        results.push_back(calc(nums, k));
    }
    for (vector<long long> r : results) {
        for (long long x : r) cout << x << " ";
        cout << endl;
    }
    return 0;
}