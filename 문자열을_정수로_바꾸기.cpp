#include <iostream>
using namespace std;

int solution(string s) {
	bool plus = true;
	if (s[0] == '-') {
		s = s.substr(1);
		plus = false;
	}
	else if (s[0] == '+')
		s = s.substr(1);

	int result = 0;
	for (int i = 0; i < s.length(); i++)
		result = result * 10 + (s[i] - '0');
	if (!plus) result = -result;

	return result;
}
