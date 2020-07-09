#include <iostream>
using namespace std;

char prime[1000001];

int solution(int n) {
	for (int i = 2; i <= n; i++)
		prime[i] = 1;

	for (int i = 2; i <= n; i++)
		if (prime[i])
			for (int j = i * 2; j <= n; j += i)
				prime[j] = 0;

	int cnt = 0;
	for (int i = 2; i <= n; i++)
		if (prime[i]) cnt++;

	return cnt;
}
