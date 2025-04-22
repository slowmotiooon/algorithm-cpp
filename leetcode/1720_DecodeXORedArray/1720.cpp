#include <iostream>
#include "solution1.h"
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> encoded(n);
    for(int& x:encoded) cin>>x;

    int first;
    cin>>first;

    vector<int> ans = decode(encoded,first);
}

// https://leetcode.cn/problems/decode-xored-array/description/     1284