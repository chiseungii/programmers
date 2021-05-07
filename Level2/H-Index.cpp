#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(vector<int> citations) {
	// 벡터 정렬(내림차순)
	sort(citations.begin(), citations.end(), greater<int>());
	int max_citation = citations[0];	// 최대 인용 횟수
	int index = 0;	// index of citations

	while (max_citation >= 0) {
		// 최대 인용 횟수까지 index 옮김
		for (; index < citations.size() && citations[index] >= max_citation; index++);

		if (index >= max_citation) return max_citation;
		else max_citation--;
	}
}
