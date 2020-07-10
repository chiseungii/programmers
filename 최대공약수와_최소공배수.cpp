#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
	int min, max;
	if (n <= m) {
		min = n;
		max = m;
	}
	else {
		min = m;
		max = n;
	}

	vector<int> answer;
	for (int i = min; i >= 1; i--) {
		if (n % i == 0 && m % i == 0) {
			answer.push_back(i);
			break;
		}
	}

	for (int i = max; i <= n * m; i++) {
		if (i % n == 0 && i % m == 0) {
			answer.push_back(i);
			break;
		}
	}

	return answer;
}
