#include <iostream>
#include <string>
using namespace std;

string solution(string s) {
	if (s.length() % 2)
		return s.substr(s.length() / 2, 1);
	else
		return s.substr((s.length() - 1) / 2, 2);
}
