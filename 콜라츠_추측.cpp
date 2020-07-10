#include <iostream>
using namespace std;

int solution(int num) {
	long long n = num;
	int cnt = 0;
	while (n != 1) {
		if (cnt == 500) {
			cnt = -1 ;
			break;
		}
		cnt++;

		if (n % 2) {
			n *= 3;
			n++;
		}
		else n /= 2;
	}

	return cnt;
}
