#include <iostream>
using namespace std;

string solution(string s, int n) {
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			if (isupper(s[i])) {
				int tmp = s[i] - 'A';
				tmp += n;
				tmp %= 26;
				s[i] = tmp + 'A';
			}
			else {
				int tmp = s[i] - 'a';
				tmp += n;
				tmp %= 26;
				s[i] = tmp + 'a';
			}
		}
	}

	return s;
}
