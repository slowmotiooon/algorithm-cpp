#pragma once

#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<int, int>> calls;
    vector<int> ans(n, 0);
    for (string& s : logs) {
        int f = s.find(':');
        int l = s.rfind(':');
        int func = stoi(s.substr(0, f));
        int position = stoi(s.substr(l + 1));
        if (s[f + 1] == 's') {
            if (!calls.empty()) ans[calls.top().first] += (position - calls.top().second);
            calls.push({ func, position });
        }
        else {
            ans[func] += (position - calls.top().second + 1);
            calls.pop();
            if (!calls.empty()) calls.top().second = position + 1;
        }
    }
    return ans;
}

// 通过 | 0ms | 18.16MB
// O(k) | O(k) k为logs数量
// 将函数的调用模拟为栈，栈记录了函数编号和**当前阶段**调用的起始时间。函数入栈时先结算栈顶函数运行时长，再入栈；函数出栈时先结算栈顶函数运行时长，然后出栈，最后设置出栈后的栈顶函数的该阶段调用的起始时间。
