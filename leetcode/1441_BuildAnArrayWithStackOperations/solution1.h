#pragma once

#include <string>
#include <vector>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    for (int i = 0; i < target.size(); i++) {
        if (i == 0) {
            for (int j = 1; j < target[i]; j++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        else {
            for (int j = target[i - 1] + 1; j < target[i]; j++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        ans.push_back("Push");
    }
    return ans;
}

// 通过 | 0ms | 10.52MB
// O(n) | O(1)