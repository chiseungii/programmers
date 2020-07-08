#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NO_CLOTHES 0
#define HAVE_CLOTHES 1
#define MORE_CLOTHES 2

int students[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
	for (int i = 0; i <= n + 1; i++)
		students[i] = HAVE_CLOTHES;
	for (int i = 0; i < reserve.size(); i++)
		students[reserve[i]]++;
	for (int i = 0; i < lost.size(); i++)
		students[lost[i]]--;
	
	for (int i = 1; i <= n; i++) {
		if (students[i] == NO_CLOTHES) {
			if (students[i - 1] == MORE_CLOTHES && students[i + 1] <= 1) {
				students[i - 1] = HAVE_CLOTHES;
				students[i] = HAVE_CLOTHES;
			}
			else if (students[i - 1] <= 1 && students[i + 1] == MORE_CLOTHES) {
				students[i + 1] = HAVE_CLOTHES;
				students[i] = HAVE_CLOTHES;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (students[i] == NO_CLOTHES)
			if (students[i - 1] == MORE_CLOTHES && students[i + 1] == MORE_CLOTHES)
				students[i]++;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (students[i])
			cnt++;

	return cnt;
}
