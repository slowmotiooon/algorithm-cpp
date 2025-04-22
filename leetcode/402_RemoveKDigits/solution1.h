#pragma once

#include <vector>
#include <deque>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    deque<char> st;
    st.push_back('\0');
    int counter = 0;
    for (int i = 0; i < num.size(); i++) {
        while (st.back() > num[i] && counter < k) {
            st.pop_back();
            counter++;
        }
        st.push_back(num[i]);
    }
    while (counter < k) {
        st.pop_back();
        counter++;
    }
    st.pop_front();
    string ans = "";
    while (!st.empty()){
        if (st.front() != '0' || !ans.empty()) ans += st.front();
        st.pop_front();
    }
    return ans.empty() ? "0" : ans;
}
