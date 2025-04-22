#include "solution2.h"
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> rooms = { { 1, 4 }, { 5 }, { 3 }, { 4, 5 }, { 2 }, {} };
    cout << canVisitAllRooms(rooms) << endl;
    return 0;
}

// https://leetcode.cn/problems/keys-and-rooms  1412