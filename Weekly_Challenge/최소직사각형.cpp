// https://programmers.co.kr/learn/courses/30/lessons/86491
// 시뮬레이션

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int max_height = 0, max_width = 0;

	for (vector<int> size : sizes) {
		// 가로가 더 길게 맞추기
		if (size[0] < size[1]) {
			int tmp = size[0];
			size[0] = size[1];
			size[1] = tmp;
		}

		if (size[0] > max_height) max_height = size[0];
		if (size[1] > max_width) max_width = size[1];
	}

	return max_height * max_width;
}
