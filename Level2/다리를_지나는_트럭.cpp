#include <iostream>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int sec = 0;
	vector<pair<int, int>> bridge;	// 차 무게, 이동 거리
	int weights = 0;

	while (1) {
		// 초 증가
		sec++;

		// 다리에 있는 트럭들 거리 이동
		for (int i = 0; i < bridge.size(); i++)
			bridge[i].second++;

		// 앞 차 도착했는지 체크
		if (!bridge.empty() && bridge.front().second > bridge_length) {
			weights -= bridge.front().first;
			bridge.erase(bridge.begin());
		}

		// 새로 다리에 오를 수 있으면 출발
		if (!truck_weights.empty() && truck_weights.front() + weights <= weight) {
			weights += truck_weights.front();
			bridge.push_back(make_pair(truck_weights.front(), 1));
			truck_weights.erase(truck_weights.begin());
		}

		if (bridge.empty() && truck_weights.empty()) break;
	}

	return sec;
}
