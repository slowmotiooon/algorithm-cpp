#pragma once

#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    stack<pair<int, char>> res;
    res.push({ 0, '+' });

    for (int i = 0; i < s.size();) {
        if (s[i] >= '0' && s[i] <= '9') {
            int nextidx = i;
            int current = 0;
            for (; s[nextidx] >= '0' && s[nextidx] <= '9'; nextidx++) {
                current = current * 10 + (s[nextidx] - 48);   // 括住防止int越界
            }

            if (res.top().second == '+')
                res.top().first += current;
            else
                res.top().first -= current;
            i = nextidx;
            continue;
        }
        else if (s[i] == '+' || s[i] == '-')
            res.top().second = s[i];
        else if (s[i] == '(')
            res.push({ 0, '+' });
        else if (s[i] == ')') {
            int val = res.top().first;
            res.pop();
            if (res.top().second == '+')
                res.top().first += val;
            else
                res.top().first -= val;
        }
        i++;
    }
    return res.top().first;
}

// 通过 | 3ms | 11.00MB
// O(n) | O(n)