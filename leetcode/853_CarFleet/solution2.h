#pragma once

#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
	map<int, double> cars;
	for (int i = 0; i < position.size(); i++) {
		cars[position[i]] = (target - position[i]) / (double)speed[i];
	}
	stack<double> st;
	vector<double> times;
	st.push(INT_MAX);
	for (auto it = cars.rbegin(); it != cars.rend(); it++) {
		while (it->second > st.top()) st.pop();
		times.push_back(st.top() == INT_MAX ? 0 : st.top());
		st.push(it->second);
	}
	int ans = 0;
	for (double i : times) ans += (i == 0);
	return ans;
}

// 通过 | 286ms | 105.54MB
// O(n*log(n)) 创建map的时间复杂度是O(n*log(n)) | O(n)
// 两种方法的时间复杂度相同，为什么第二种的运行时间要第一种慢？
// 答：因为map在创建时，以及使用反向迭代器遍历时都有额外的时间和空间开销