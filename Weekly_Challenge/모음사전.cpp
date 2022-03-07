// https://programmers.co.kr/learn/courses/30/lessons/84512
// 수학, 시뮬레이션, 배열

#include <string>
#include <vector>

using namespace std;

int solution(string word) {
	int weights[5] = { 781, 156, 31, 6, 1 };
	int result = 0;

	for (int i = 0; i < word.length(); i++) {
		int tmp;
		if (word[i] == 'A') tmp = 0;
		else if (word[i] == 'E') tmp = 1;
		else if (word[i] == 'I') tmp = 2;
		else if (word[i] == 'O') tmp = 3;
		else if (word[i] == 'U') tmp = 4;

		result++;
		result += weights[i] * tmp;
	}

	return result;
}
