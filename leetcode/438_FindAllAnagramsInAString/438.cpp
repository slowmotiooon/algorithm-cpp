#include <iostream>
#include "solution3.h"
using namespace std;

int main() {
	string s, p;
	cin >> s >> p;

	vector<int> result = findAnagrams(s, p);

	for (int i : result) {
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}