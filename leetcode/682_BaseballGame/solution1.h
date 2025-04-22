#pragma once

#include <numeric>
#include <string>
#include <vector>
using namespace std;

int calPoints(vector<string>& operations) {
    vector<int> scores;
    for (string x : operations) {
        if ((x[0] >= '0' && x[0] <= '9') || x[0] == '-')
            scores.push_back(stoi(x));
        else if (x == "C")
            scores.pop_back();
        else if (x == "D")
            scores.push_back(2 * scores.back());
        else if (x == "+")
            scores.push_back(*(scores.end() - 1) + *(scores.end() - 2));
    }
    return accumulate(scores.begin(), scores.end(), 0);
}

// 通过 | 0ms | 11.84MB
// O(n) | O(n)