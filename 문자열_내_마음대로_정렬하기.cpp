#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp_i;

bool compare(string a, string b) {
	if (a[cmp_i] == b[cmp_i]) return a < b;
	else return a[cmp_i] < b[cmp_i];
}

vector<string> solution(vector<string> strings, int n) {
	cmp_i = n;
	sort(strings.begin(), strings.end(), compare);
	return strings;
}
