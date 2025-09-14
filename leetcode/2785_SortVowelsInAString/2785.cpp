#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    virtual string sortVowels(string s) = 0;
};

// 找到元音字母，然后排序
// accepted 23ms 20MB
// O(nlogn) O(n)
class Solution1 : public Solution
{
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> vowels;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
                s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowels.push_back(s[i]);
                idx.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowels.size(); i++) s[idx[i]] = vowels[i];
        return s;
    }
};

int main() {
    string s = "lEetcOde";
    cout << (new Solution1())->sortVowels(s) << endl;
    return 0;
}