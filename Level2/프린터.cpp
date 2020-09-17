#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char check[100];

int solution(vector<int> priorities, int location) {
	// init
	vector<int> sorted = priorities;
	sort(sorted.begin(), sorted.end(), greater<int>());

	// 인쇄 시뮬레이션
	int cnt = 0, index = 0;
	while (1) {
		cnt++;
		while (check[index] || priorities[index] != sorted.front()) {
			index++; index %= priorities.size();
		}

		if (index == location) break;
		else {
			check[index] = 1;
			sorted.erase(sorted.begin());
		}
	}

	return cnt;
}
