#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    TreeNode* root = new TreeNode(10,
                                  new TreeNode(5,
                                               new TreeNode(3, new TreeNode(3), new TreeNode(-2)),
                                               new TreeNode(2, new TreeNode(1))),
                                  new TreeNode(-3, new TreeNode(11)));

    cout << pathSum(root, 8) << endl;
    return 0;
}

// https://leetcode.cn/problems/path-sum-iii