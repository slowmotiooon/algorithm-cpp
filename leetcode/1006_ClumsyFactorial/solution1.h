#pragma once

#include <queue>
using namespace std;

int clumsy(int n) {
    int ans = 0;
    int buf = n;
    for (int i = 0; i < n - 1; i++) {
        if (i % 4 == 0)
            buf *= n - i - 1;
        else if (i % 4 == 1)
            buf /= n - i - 1;
        else if (i % 4 == 2)
            ans += n - i - 1;
        else if (i == 3)
            ans += buf;
        else
            ans -= buf;
        buf = n - i - 1;
    }
    return n < 5 ? ans + buf : ans - buf;
}