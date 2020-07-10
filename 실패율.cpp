#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int players_through_stage[501];	// 스테이지 도달한 플레이어 수
int players_on_stage[501];		// 현재 스테이지에 있는 플레이어 수

bool compare(pair<int, double> a, pair<int, double>b) {
	if (a.second == b.second)
		return a.first < b.first;
	else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	for (int i = 0; i < stages.size(); i++) {
		players_on_stage[stages[i]]++;
		for (int j = 1; j <= stages[i]; j++)
			players_through_stage[j]++;
	}

	vector<pair<int, double>> rate;
	for (int i = 1; i <= N; i++) {
		double rate_fail;
		if (players_through_stage[i] == 0) rate_fail = 0;
		else rate_fail = (double)players_on_stage[i] / (double)players_through_stage[i];
		rate.push_back(pair<int, double>(i, rate_fail));
	}
	sort(rate.begin(), rate.end(), compare);

	vector<int> answer;
	for (int i = 0; i < rate.size(); i++)
		answer.push_back(rate[i].first);

	return answer;
}
