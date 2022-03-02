// https://programmers.co.kr/learn/courses/30/lessons/87946?language=cpp
// backtracking 사용

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;

// 던전, 현재 피로도, 방문한 던전, 현재 던전, 던전 방문 횟수(현재 포함)
void backtracking(vector<vector<int>> dungeons, int cur_k, vector<bool> visit, int cur_dungeon, int cnt) {
	// 지금 던전 못 가면 리턴
	if (cur_k < dungeons[cur_dungeon][0]) {
		if (cnt - 1 > max_cnt) max_cnt = cnt - 1;
	}
	else {
		cur_k -= dungeons[cur_dungeon][1];

		bool all_visit = true;
		for (int i = 0; i < dungeons.size(); i++) {
			if (visit[i]) continue;

			all_visit = false;
			visit[i] = true;
			backtracking(dungeons, cur_k, visit, i, cnt + 1);
			visit[i] = false;
		}

		if (all_visit && cnt > max_cnt) max_cnt = cnt;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	vector<bool> visit;
	for (int i = 0; i < dungeons.size(); i++) visit.push_back(false);

	for (int i = 0; i < dungeons.size(); i++) {
		visit[i] = true;
		backtracking(dungeons, k, visit, i, 1);
		visit[i] = false;
	}

	return max_cnt;
}
