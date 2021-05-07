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

vector<int> solution(int brown, int yellow) {
	for (int i = 1; i <= sqrt(yellow); i++) {
		// yellow의 약수인지
		if (yellow % i) continue;
		else {
			// brown의 조건도 만족하는지
			if (2 * (i + yellow / i) + 4 == brown) {
				if (i >= yellow / i) return { i + 2, yellow / i + 2 };
				else return { yellow / i + 2, i + 2 };
			}
		}
	}
}
