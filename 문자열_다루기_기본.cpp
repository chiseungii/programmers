#include <iostream>
using namespace std;

bool solution(string s) {
	if (s.length() != 4 && s.length() != 6) return false;
	else {
		bool only_digit = true;
		for (int i = 0; i < s.length(); i++)
			if (!isdigit(s[i])) only_digit = false;

		return only_digit;
	}
}
