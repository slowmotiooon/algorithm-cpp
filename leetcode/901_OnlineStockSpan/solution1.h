#pragma once

#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> prices;
    int counter = -1;
    StockSpanner() {
        prices.push({ -1,INT_MAX });
    }

    int next(int price) {
        while (price >= prices.top().second) prices.pop();
        counter++;
        int ans = counter - prices.top().first;
        prices.push({ counter,price });
        return ans;
    }
};

// 通过 | 245ms | 88.32MB
// O(n) | O(n) (最坏情况下)
// 纯纯的单调栈。所谓“股票价格小于或等于今天价格的最大连续日数”，关键在于找到“股票价格第一次大于当天的天数”