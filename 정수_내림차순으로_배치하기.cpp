#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
	vector<int> tmp;
	while (n > 0) {
		tmp.push_back(n % 10);
		n /= 10;
	}
	sort(tmp.begin(), tmp.end(), greater<int>());

	long long answer = 0;
	for (int i = 0; i < tmp.size(); i++)
		answer = answer * 10 + tmp[i];

	return answer;
}
