#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
using namespace std;

bool isPrime[10000000];

void findPrime() {
	fill_n(isPrime, 10000000, true);
	isPrime[0] = isPrime[1] = false;

	// 짝수 제거
	for (int i = 4; i < 10000000; i += 2)
		isPrime[i] = false;

	// 소수 찾기
	for (int i = 3; i < 10000000; i += 2) {
		if (isPrime[i]) {
			for (int j = i * 2; j < 10000000; j += i)
				isPrime[j] = false;
		}
	}
}

int solution(string numbers) {
	// 소수 찾기
	findPrime();

	int len = numbers.length();	// 숫자 길이
	set<int> primes;	// 찾은 소수

	for (int i = 1; i <= len; i++) {	// i: 숫자 길이
		vector<int> cmb;	// 조합

		// 조합 숫자 넣기
		for (int j = 0; j < i; j++)
			cmb.push_back(j);
		for (int j = 0; j < len - i; j++)
			cmb.push_back(-1);

		string number = "";	// 만들 숫자
		vector<int> cpy = cmb;

		while (1) {
			number = "";
			for (int j = 0; j < i; j++)
				number += ' ';

			for (int j = 0; j < len; j++) {
				if (cmb[j] > -1) {
					number[cmb[j]] = numbers[j];
				}
			}

			int int_number = stoi(number);
			if (isPrime[int_number]) primes.insert(int_number);

			next_permutation(cmb.begin(), cmb.end());
			if (cmb == cpy) break;
		}
	}

	return primes.size();
}
