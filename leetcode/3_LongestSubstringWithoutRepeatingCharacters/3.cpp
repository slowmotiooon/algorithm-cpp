#include "solution2.h"
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	cout << lengthOfLongestSubstring(s) << endl;

	return 0;
}