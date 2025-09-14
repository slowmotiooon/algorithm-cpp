#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    virtual int minRemoval(vector<int>& nums, int k) = 0;
};

// TLE
// 使用递归，方法肯定对，不过还是很慢。
class Solution1 : public Solution
{
    int check(vector<int>& nums, int min, int max, int k, int ans = 0) {
        if (nums[min] * k >= nums[max]) return ans;
        int move_l = check(nums, min + 1, max, k, ans + 1);
        int move_r = check(nums, min, max - 1, k, ans + 1);
        return move_l > move_r ? move_r : move_l;
    }

public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min = 0, max = nums.size() - 1;
        return check(nums, min, max, k);
    }
};

// ac 25ms 102.59mb
// 滑动窗口
class Solution2 : public Solution
{
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int moves = nums.size() - 1;
        int ans = INT_MAX;
        while (r < nums.size()) {
            if ((long long)nums[l] * k < nums[r]) {
                l += 1;
                moves += 1;
            }
            else {
                r += 1;
                moves -= 1;
            }
            ans = (moves < ans) ? moves : ans;
        }
        return ans + 1;
    }
};

int main() {
    vector<int> nums = { 1, 6, 2, 9 };
    int k = 2;
    cout << (new Solution2())->minRemoval(nums, k) << endl;
    return 0;
}
