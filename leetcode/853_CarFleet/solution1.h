#pragma once

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<pair<int, int>> cars;

double time(int& i, int& target) {
	return ((target - cars[i].first) / (double)cars[i].second);
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
	for (int i = 0; i < speed.size(); i++) {
		cars.push_back({ position[i],speed[i] });
	}
	sort(cars.begin(), cars.end(), [&](pair<int, int>x, pair<int, int> y) {return x.first < y.first; });
	vector<double> m(cars.size());
	stack<double> st;
	st.push(INT_MAX);
	for (int i = cars.size() - 1; i >= 0; i--) {
		while (time(i,target) > st.top()) st.pop();
		m[i] = st.top() == INT_MAX ? 0 : st.top();
		st.push(time(i,target));
	}
	int ans = 0;
	for (double x : m) ans += x == 0;
	return ans;
}

// Í¨¹ý | 147ms | 83.43MB
// O(n*log(n)) | O(n)