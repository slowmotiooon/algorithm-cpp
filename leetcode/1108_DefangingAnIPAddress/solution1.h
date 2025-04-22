#pragma once

#include <vector>
using namespace std;

string defangIPaddr(string address) {
	string result;
	for (int i = 0; i<address.length(); i++) {
		if (address[i] == '.') result += "[.]";
		else result += address[i];
	}
	return result;
}

// 运行结果：
// 通过 | 2ms | 7.22MB
// O(n) | O(1)