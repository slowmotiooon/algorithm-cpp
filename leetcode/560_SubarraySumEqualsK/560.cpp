#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        unordered_map<int, int> hashmap;
        int ans = 0;
        for (int x : sum) {
            int value = k + x;
            auto it = hashmap.find(x);
            if (it != hashmap.end()) ans += it->second;
            hashmap[value] += 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 1, 1, 1 };
    int k = 2;
    Solution* s = new Solution();
    cout << s->subarraySum(nums, k) << endl;
    return 0;
}