#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> hours(n);
    for (int& x : hours) cin >> x;

    cout << countCompleteDayPairs(hours) << endl;
    return 0;
}

// https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/description/        1385