#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

string solution(string number, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < number.length(); j++) {
			// 제일 뒷자리면 바로 삭제
			if (j == number.length() - 1) {
				number.erase(j, 1);
				break;
			}
			// 뒤의 숫자보다 작으면 삭제
			else if (number[j] < number[j + 1]) {
				number.erase(j, 1);
				break;
			}
		}
	}

	return number;
}
