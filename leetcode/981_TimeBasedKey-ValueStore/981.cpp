#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	TimeMap* m = new TimeMap();

	m->set("a", "bar", 1);
	m->set("x", "b", 3);
	cout << m->get("b", 3) << endl;
	m->set("foo", "bar2", 4);
	cout << m->get("foo", 4) << endl;
	cout << m->get("foo", 5) << endl;
	return 0;
}

// https://leetcode.cn/problems/time-based-key-value-store/description/		1575