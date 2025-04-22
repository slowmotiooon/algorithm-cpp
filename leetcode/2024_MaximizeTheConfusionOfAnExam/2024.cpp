#include <iostream>
#include "solution1.h"
using namespace std;

int main() {
	string answerKey;
	int k;
	cin >> answerKey >> k;
	cout << maxConsecutiveAnswers(answerKey, k) << endl;
	return 0;
}

// https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/?envType=daily-question&envId=2024-09-02		1643