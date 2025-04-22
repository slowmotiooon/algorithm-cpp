#include <iostream>
#include "solution1.h"
using namespace std;

int main(){
    string num;
    cin >> num;

    int k;
    cin >> k;

    cout << removeKdigits(num, k) << endl;
    return 0;
}

// https://leetcode.cn/problems/remove-k-digits/description/
