#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	vector<char> tmp;
	for (int i = 0; i < s.length(); i++)
		tmp.push_back(s[i]);
	sort(tmp.begin(), tmp.end(), greater<char>());

	string result = "";
	for (int i = 0; i < tmp.size(); i++)
		result += tmp[i];

	return result;
}
