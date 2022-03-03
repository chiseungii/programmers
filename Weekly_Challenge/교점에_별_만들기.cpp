// https://programmers.co.kr/learn/courses/30/lessons/87377
// 수학, 시뮬레이션
// ax + by + c = 0 과 dx + ey + f = 0 의 교점
// x좌표 = (ce-bf) / (bd-ae)  y좌표 = (af-cd) / (bd-ae)

#include <string>
#include <vector>

using namespace std;

#define RANGE 10000000000000001

vector<string> solution(vector<vector<int>> line) {
	vector<pair<long long, long long>> dots;	// 교점 집합
	long long min_x = RANGE, max_x = -RANGE;
	long long min_y = RANGE, max_y = -RANGE;

	// 교점 구하기
	for (int i = 0; i < line.size() - 1; i++) {
		long long a = line[i][0], b = line[i][1], c = line[i][2];

		for (int j = i + 1; j < line.size(); j++) {
			long long d = line[j][0], e = line[j][1], f = line[j][2];

			// 교점의 x좌표가 정수인지 확인
			long long tmp1 = c * e - b * f;
			long long tmp2 = b * d - a * e;
			if (tmp2 == 0 || tmp1 % tmp2 != 0) continue;
			long long x = tmp1 / tmp2;

			// 교점의 y좌표가 정수인지 확인
			tmp1 = a * f - c * d;
			tmp2 = b * d - a * e;
			if (tmp2 == 0 || tmp1 % tmp2 != 0) continue;
			long long y = tmp1 / tmp2;

			dots.push_back(make_pair(x, y));
			if (x < min_x) min_x = x;
			if (x > max_x) max_x = x;
			if (y < min_y) min_y = y;
			if (y > max_y) max_y = y;
		}
	}

	long long dis_x = max_x - min_x + 1;
	long long dis_y = max_y - min_y + 1;

	string xy = "";	// x축 한 줄
	vector<string> result;
	for (long long i = 0; i < dis_x; i++) xy += '.';
	for (long long i = 0; i < dis_y; i++) result.push_back(xy);

	// 별 찍기
	for (pair<long long, long long> dot : dots) {
		long long dot_x = dot.first - min_x;
		long long dot_y = dot.second - min_y;
		dot_y = dis_y - 1 - dot_y;

		result[dot_y][dot_x] = '*';
	}

	return result;
}
