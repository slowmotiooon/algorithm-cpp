#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int placeSum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> boxes;
    for (int i = lowLimit; i <= highLimit; i++) { boxes[placeSum(i)]++; }
    return max_element(boxes.begin(),
                       boxes.end(),
                       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; })
        ->second;
}

// 通过 | 11ms | 8.23MB
// O(n*k) | O(n) n=highLimit-lowLimit+1, k是i的平均位数
// 需要注意，max_element函数只能比较unordered_map中每个元素的键的最大值，也就是说，该函数返回的是键值最大的元素的迭代器，而不是值最大的元素的迭代器。