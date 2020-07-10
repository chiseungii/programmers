#include <iostream>
using namespace std;

#define NON_SCORE 99999999

int solution(string dartResult) {
	int answer = 0;
	int index = 0, before_score = NON_SCORE;
	for (int i = 0; i < 3; i++) {
		// 기본 점수
		int score = dartResult[index++] - '0';
		// 10점일 경우
		if (dartResult[index] == '0') {
			score = 10;
			index++;
		}

		// 보너스 점수
		char bonus = dartResult[index++];
		if (bonus == 'D') score *= score;
		else if (bonus == 'T') score = score * score * score;

		// 옵션 검사
		if (index >= dartResult.length());
		else if (dartResult[index] == '#') {
			score = -score;
			index++;
		}
		else if (dartResult[index] == '*') {
			if (before_score == NON_SCORE) score *= 2;
			else {
				score *= 2;
				answer += before_score;
			}
			index++;
		}

		answer += score;
		before_score = score;
	}

	return answer;
}
