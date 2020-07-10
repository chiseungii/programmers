#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define LEFT 0
#define RIGHT 1
#define DONT_KNOW 2

int dis(int hand, int num) {
	int result = abs(hand / 10 - num / 10);
	result += abs(hand % 10 - num % 10);

	return result;
}

string solution(vector<int> numbers, string hand) {
	int loc[10] = { 42, 11, 12, 13, 21, 22, 23, 31, 32, 33 };
	int hands[10] = { 2, 0, 2, 1, 0, 2, 1, 0, 2, 1 };
	int left = 41, right = 43;
	string answer = "";

	for (int i = 0; i < numbers.size(); i++) {
		int a = numbers[i];

		if (hands[a] == LEFT) {
			answer += "L";
			left = loc[a];
		}
		else if (hands[a] == RIGHT) {
			answer += "R";
			right = loc[a];
		}
		else {
			int left_dis = dis(left, loc[a]);
			int right_dis = dis(right, loc[a]);

			if (left_dis == right_dis) {
				if (hand == "right") {
					answer += "R";
					right = loc[a];
				}
				else {
					answer += "L";
					left = loc[a];
				}
			}
			else if (left_dis < right_dis) {
				answer += "L";
				left = loc[a];
			}
			else {
				answer += "R";
				right = loc[a];
			}
		}
	}

	return answer;
}
