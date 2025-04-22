#include "solution1.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (vector<int>& x : points) cin >> x[0] >> x[1];

    cout << numberOfBoomerangs(points) << endl;
    return 0;
}