#pragma once

#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<int> primes;

bool isPrime(int n) {
	if (n <= 3) return n > 1;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int smallestValue(int n) {
	if (isPrime(n) || n == 4) return n;

	int result = 0;
	int factor = 2;
	while (n != 1) {
		if (primes.find(factor) == primes.end()) {
			if (isPrime(factor)) primes.insert(factor);
			else {
				factor++;
				continue;
			}
		}

		if (n % factor == 0) {
			result += factor;
			n = n / factor;
			factor = 2;
		}
		else {
			factor++;
		}
	}

	return smallestValue(result);
}

// 运行结果：
// 通过 | 46ms | 13.50MB
// 写了单独的判断质数的函数，这个函数可以省略。