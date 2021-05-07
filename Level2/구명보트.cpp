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

int solution(vector<int> people, int limit) {
	// 몸무게 벡터 정렬
	sort(people.begin(), people.end());

	int left = 0;
	int right = people.size() - 1;
	int cnt = 0;

	while (left <= right) {
		// 둘 다 태울 수 있으면
		if (people[left] + people[right] <= limit) {
			left++; right--;
			cnt++;
		}
		// 못 태우면
		else {
			right--;
			cnt++;
		}
	}

	return cnt;
}
