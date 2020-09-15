#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int sec[100000];

vector<int> solution(vector<int> prices) {
	// init
	for (int i = 0; i < prices.size(); i++)
		sec[i] = 0;

	// cal
	stack<int> S;	// 들어온 시간
	for (int i = 0; i < prices.size(); i++) {
		int tmp = prices[i];

		// push
		if (S.empty() || tmp >= prices[S.top()]) {
			S.push(i);
		}
		// pop
		else {
			while (tmp < prices[S.top()]) {
				sec[S.top()] = i - S.top();
				S.pop();
				if (S.empty()) break;
			}
			S.push(i);
		}
	}

	// 마지막에 남아있는 것 계산
	while (!S.empty()) {
		int tmp = S.top();
		S.pop();

		sec[tmp] = prices.size() - 1 - tmp;
	}

	// return
	vector<int> result;
	for (int i = 0; i < prices.size(); i++)
		result.push_back(sec[i]);

	return result;
}
