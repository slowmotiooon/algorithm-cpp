#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    virtual int totalFruit(vector<int>& fruits) = 0;
};

// acc 59ms 73.37MB
// O(n) O(1)
// 滑动窗口，用哈希表模拟“篮子”。
// 由于“篮子”的数量上限不会超过2，因此对篮子的所有增删改查操作的时间复杂度都是O(1)，篮子的空间复杂度也是O(1)
class Solution1 : public Solution
{
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> bucket;
        int l = 0;
        int ans = 0, total = 0;
        for (int r = 0; r < fruits.size(); r++) {
            if (bucket.find(fruits[r]) == bucket.end()) {
                while (bucket.size() >= 2) {
                    bucket[fruits[l]]--;
                    total--;
                    if (bucket[fruits[l]] == 0) bucket.erase(fruits[l]);
                    l++;
                }
            }
            bucket[fruits[r]]++;
            total++;
            ans = max(total, ans);
        }
        return ans;
    }
};

int main() {
    vector<int> fruits = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    cout << (new Solution1())->totalFruit(fruits) << endl;
    return 0;
}