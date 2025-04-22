#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
	//sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());
	int maxDist = 0;
	for (int x : houses) {
		int left = 0;
		int right = heaters.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (heaters[mid] >= x) right = mid;
			else left = mid + 1;
		}
		if (right == 0) maxDist = max(maxDist, abs(x - heaters[right]));
		else if (right == heaters.size()) maxDist = max(maxDist, abs(x - heaters[right - 1]));
		else maxDist = max(maxDist, min(abs(x - heaters[right]), abs(x - heaters[right - 1])));
	}
	return maxDist;
}

// 通过 | 51ms | 28.48MB
// O((m+n)*log(n)) m为houses数量，n为heaters数量 | O(1)
// 思路来自：https://leetcode.cn/problems/heaters/solutions/1165760/gong-nuan-qi-by-leetcode-solution-rwui
// solution1的方法是确定半径的下界和上界，然后对半径进行二分查找。
// 但是检测该半径是否覆盖全部房屋的函数的时间复杂度是O(m*n)，造成超时。
