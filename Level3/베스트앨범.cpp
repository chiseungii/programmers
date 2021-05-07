#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
	return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	map<string, int> genreCnt;	// <장르, 총 재생 횟수>
	map<string, pair<int, int>> playNum;	// <장르, <가장 많이 재생된 번호, 그 다음 번호>>

	for (int i = 0; i < genres.size(); i++) {
		// 장르별 재생 횟수 카운트
		genreCnt[genres[i]] += plays[i];

		// 처음 나온 장르일 경우
		if (genreCnt[genres[i]] == plays[i]) {
			playNum[genres[i]] = make_pair(i, -1);
		}
		else {
			// 재생 횟수가 가장 많을 경우
			if (plays[i] > plays[playNum[genres[i]].first]) {
				playNum[genres[i]].second = playNum[genres[i]].first;
				playNum[genres[i]].first = i;
			}
			// 두 번째보다 많을 경우
			else if (plays[i] > plays[playNum[genres[i]].second]) {
				playNum[genres[i]].second = i;
			}
		}
	}

	// 벡터로 교체
	vector<pair<string, int>> v_genreCnt(genreCnt.begin(), genreCnt.end());
	// 벡터 정렬
	sort(v_genreCnt.begin(), v_genreCnt.end(), compare);

	// 재생 순서 저장
	vector<int> result;

	for (int i = 0; i < v_genreCnt.size(); i++) {
		string genre = v_genreCnt[i].first;

		// 첫째 순위 저장
		result.push_back(playNum[genre].first);
		// 둘째 순위 있으면 저장
		if (playNum[genre].second > -1)
			result.push_back(playNum[genre].second);
	}

	return result;
}
