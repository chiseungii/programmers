#include <iostream>
#include <string>
using namespace std;

int stick[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
int name_stick[20];
char check[20];

int solution(string name) {
	int len = name.length();

	// 위아래 횟수 계산
	int rest_cnt = 0;
	for (int i = 0; i < len; i++) {
		name_stick[i] = stick[name[i] - 'A'];
		if (name[i] != 'A') rest_cnt++;
	}

	int cnt = 0;
	// 제일 앞글자
	cnt += name_stick[0];
	check[0] = 1;
	if (name[0] != 'A') rest_cnt--;

	// 나머지 단어들 모두 반복
	int index = 0;
	while (rest_cnt) {
		// 오른쪽으로 갈 때 거리
		int right_index = index + 1, right_cnt = 1;
		if (right_index >= len) right_index -= len;
		while (check[right_index] || name[right_index] == 'A') {
			right_index++; if (right_index >= len) right_index -= len;
			right_cnt++;
		}

		// 왼쪽으로 갈 때 거리
		int left_index = index - 1, left_cnt = 1;
		if (left_index < 0) left_index += len;
		while (check[left_index] || name[left_index] == 'A') {
			left_index--; if (left_index < 0) left_index += len;
			left_cnt++;
		}

		// 더 가까운 곳으로 이동
		if (right_cnt <= left_cnt) {
			cnt += right_cnt;
			index = right_index;
			cnt += name_stick[index];
			check[index] = 1;
			rest_cnt--;
		}
		else {
			cnt += left_cnt;
			index = left_index;
			cnt += name_stick[index];
			check[index] = 1;
			rest_cnt--;
		}
	}

	return cnt;
}
