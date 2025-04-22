#pragma once

#include <string>
#include <vector>
using namespace std;

struct TreeNode1
{
    char val;
    int index;
    vector<TreeNode1*> childs;
    TreeNode1(char v = '\0', int i = -2, vector<TreeNode1*> c = {}) {
        val = v;
        index = i;
        childs = c;
    }
};

int size(TreeNode1* p, vector<int>& ans) {
    ans[p->index]++;
    for (int i = 0; i < p->childs.size(); i++) {
        ans[p->index] += size(p->childs[i], ans);
    }
    return ans[p->index];
}

vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int n = parent.size();
    vector<TreeNode1*> tree(n);
    for (int i = 0; i < n; i++) tree[i] = new TreeNode1();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        for (int a = parent[i]; a != -1; a = parent[a]) {
            if (s[a] == s[i]) {
                parent[i] = a;
                break;
            }
        }
    }

    // 构建树
    TreeNode1* root = nullptr;
    for (int i = 0; i < n; i++) {
        tree[i]->val = s[i];
        tree[i]->index = i;
        if (parent[i] != -1) {
            tree[parent[i]]->childs.push_back(tree[i]);
        }
        else
            root = tree[i];
    }

    size(root, ans);
    return ans;
}