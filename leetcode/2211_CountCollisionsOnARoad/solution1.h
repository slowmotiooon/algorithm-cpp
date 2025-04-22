#pragma once

#include <string>
using namespace std;

int countCollisions(string directions) {
    char prev = 'L';
    int ans = 0;
    int rs = 0;
    for (char c : directions) {
        if (prev == 'S' && c == 'L') ans++;
        if (prev == 'R' && c != 'R') {
            ans += rs + (c == 'L');
            rs = 0;
        }

        if (prev == 'L')
            prev = c;
        else if (c != 'R')
            prev = 'S';
        else
            prev = 'R';

        if (c == 'R') rs++;
    }
    return ans;
}

// 通过 | 8ms | 18.91MB
// O(n) | O(1)