#include <iostream>
#include "solution2.h"
using namespace std;

int main() {
	vector<string> strList;
	int total;

	cin >> total;

	for (int i = 0; i < total; i++) {
		string buffer;
		cin >> buffer;
		strList.push_back(buffer);
	}

	vector<vector<string>> result = groupAnagrams(strList);

	for (vector<string> it : result) {
		for (string item : it) {
			cout << item << ", ";
		}
		cout << endl;
	}

	return 0;
}