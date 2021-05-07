#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int solution(vector<vector<string>> clothes) {
	map<string, int> cnt;	// <옷 종류, 개수>

	for (int i = 0; i < clothes.size(); i++) {
		cnt[clothes[i][1]]++;
	}

	int result = 1;
	map<string, int>::iterator it;

	for (it = cnt.begin(); it != cnt.end(); it++)
		result *= (it->second + 1);

	return result - 1;
}
