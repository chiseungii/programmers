#include <iostream>
using namespace std;

long long solution(int a, int b) {
	int start, end;
	if (a <= b) {
		start = a;
		end = b;
	}
	else {
		start = b;
		end = a;
	}

	long long sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;

	return sum;
}
