#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scovile, int K) {
	// 우선순위 큐에 넣음
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < scovile.size(); i++)
		PQ.push(scovile[i]);

	// 섞기
	int cnt = 0;
	while (PQ.size() > 1) {
		if (PQ.top() >= K) return cnt;

		cnt++;
		int a = PQ.top(); PQ.pop();
		int b = PQ.top(); PQ.pop();
		PQ.push(a + b * 2);
	}

	if (PQ.size() == 1 && PQ.top() >= K) return cnt;
	else return -1;
}
