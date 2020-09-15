#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> result;
	while (!progresses.empty()) {
		// 일 진행
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
			if (progresses[i] > 100) progresses[i] = 100;
		}

		int cnt = 0;
		while (!progresses.empty() && progresses.front() == 100) {
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
			cnt++;
		}

		if (cnt) result.push_back(cnt);
	}

	return result;
}
