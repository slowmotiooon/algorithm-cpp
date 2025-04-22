#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) {
        val = v;
        left = l;
        right = r;
    }
};

int dfs(TreeNode* p, vector<long long>& sums, unordered_map<long long, int>& check, int t) {
    if (p == nullptr) return 0;
    long long newSum = sums.back() + p->val;
    sums.push_back(newSum);
    int ans = 0;
    if (check.find(newSum) != check.end()) ans += check[newSum];
    check[newSum + t]++;
    ans += dfs(p->left, sums, check, t);
    ans += dfs(p->right, sums, check, t);
    sums.pop_back();
    if (check[newSum + t] == 1)
        check.erase(newSum + t);
    else
        check[newSum + t]--;
    return ans;
}

int pathSum(TreeNode* root, int targetSum) {
    vector<long long> sums = { 0 };
    unordered_map<long long, int> check;
    check[sums[0] + targetSum]++;

    return dfs(root, sums, check, targetSum);
}

// 通过 | 15ms | 21.94MB
// O(n) | O(n)
