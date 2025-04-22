#include <stack>
#include <string>
using namespace std;

int scoreOfParentheses(string s) {
    int depth = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            depth++;
        else {
            if (s[i - 1] == '(')
                ans += pow(2, --depth);
            else
                depth--;
        }
    }
    return ans;
}

// 通过 | 0ms | 7.98MB
// O(n) | O(1)
// 参考：https://leetcode.cn/problems/score-of-parentheses/solutions/1876173/gua-hao-de-fen-shu-by-leetcode-solution-we6b
// 方法三