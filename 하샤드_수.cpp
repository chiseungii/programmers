#include <iostream>
using namespace std;

bool solution(int x) {
	int sum = 0, tmp = x;
	while (tmp > 0) {
		sum += tmp % 10;
		tmp /= 10;
	}

	if (x % sum) return false;
	else return true;
}
