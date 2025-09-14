#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    virtual vector<int> getNoZeroIntegers(int n) = 0;
};

class Solution1 : public Solution
{
public:
    bool detectZero(int n) {
        while (n != 0) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            int d = n - i;
            if (!detectZero(i) && !detectZero(d)) return { i, d };
        }
        return {};
    }
};

int main() {
    vector<int> result = (new Solution1())->getNoZeroIntegers(1010);
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}