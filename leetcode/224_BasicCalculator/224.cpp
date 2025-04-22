#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    cout << calculate(s) << endl;
    return 0;
}

// https://leetcode.cn/problems/basic-calculator