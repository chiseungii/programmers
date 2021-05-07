#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
		if (p1.second == p2.second) return p1.first > p2.first;
		else return p1.second > p2.second;
	}
};

bool compare2(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> ready;	// 레디 큐
	int sec = 0;	// 현재 시각(ms)

	// 벡터 정렬
	sort(jobs.begin(), jobs.end(), compare2);
	int index = 0;	// index of jobs
	int sumTime = 0;	// 총 걸린 시간(ms)

	while (index < jobs.size()) {
		// 현재 시각까지 들어온 모든 요청 레디 큐에 넣음
		for (; index < jobs.size() && jobs[index][0] <= sec; index++)
			ready.push(make_pair(jobs[index][0], jobs[index][1]));

		// 큐가 비어있을 경우
		if (ready.empty()) {
			sec++;
			continue;
		}

		// 가장 앞에 있는 것 꺼내서 실행
		pair<int, int> front = ready.top();
		ready.pop();

		// 요청 후 기다린 시간
		sumTime += (sec - front.first);
		// 실행 시간
		sumTime += front.second;

		// 시간 이동
		sec += front.second;
	}

	// 남은 요청들은 모두 순서대로 실행
	while (!ready.empty()) {
		// 가장 앞에 있는 것 꺼내서 실행
		pair<int, int> front = ready.top();
		ready.pop();

		// 요청 후 기다린 시간
		sumTime += (sec - front.first);
		// 실행 시간
		sumTime += front.second;

		// 시간 이동
		sec += front.second;
	}

	return sumTime / jobs.size();
}
