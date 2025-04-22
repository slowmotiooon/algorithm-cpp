#pragma once

#include <string>
#include <vector>
using namespace std;

string simplifyPath(string path) {
    path += '/';
    vector<string> paths;
    int slash = 0, prevSlash = 0;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
            prevSlash = slash;
            slash = i;
            if (prevSlash == slash) continue;
            string buff = path.substr(prevSlash, slash - prevSlash);
            if (buff == "/..") {
                if (!paths.empty()) paths.pop_back();
            }
            else if (buff == "/" || buff == "/." || buff.empty()) {}
            else
                paths.push_back(buff);
        }
    }
    string ans = "";
    for (string s : paths) ans += s;
    return ans.empty() ? "/" : ans;
}

// 通过 | 0ms | 10.97MB | 12:02 | 0x
// O(Σ), Σ为path中'/'的总数 | O(Σ)
// 有些注意的地方：
// 1. substr的第二个参数是截取的字符串长度
// 2. 进行出栈之前需要先判断栈是否为空
// 3. if混淆语句含义的时候需要加大括号