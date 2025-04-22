#pragma once

#include <deque>
#include <string>
using namespace std;

string finalString(string s) {
    string ans = "";
    bool r = false;
    deque<int> q;
    for (char c : s) {
        if (c == 'i')
            r = !r;
        else
            r ? q.push_back(c) : q.push_front(c);
    }
    while (!q.empty()) {
        ans.push_back(r ? q.front() : q.back());
        r ? q.pop_front() : q.pop_back();
    }
    return ans;
}

// 通过 | 0ms | 14.16MB
// O(n) | O(n)
