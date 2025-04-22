#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> maze = vector<vector<char>>(m, vector<char>(n));
    for (vector<char>& l : maze)
        for (char& c : l) cin >> c;

    vector<int> entrance(2);
    cin >> entrance[0] >> entrance[1];

    cout << nearestExit(maze, entrance) << endl;
    return 0;
}

// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/     1638