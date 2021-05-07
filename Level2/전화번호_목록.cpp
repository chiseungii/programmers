#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool isPrefix(string s1, string s2) {
	// s1의 길이가 더 짧게 맡춤
	if (s2.length() < s1.length()) {
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// 접두어면 true, 아니면 false
	if (s2.substr(0, s1.length()) == s1)
		return true;
	else return false;
}

bool solution(vector<string> phone_book) {
	// 벡터 정렬
	sort(phone_book.begin(), phone_book.end());

	// 양옆 비교
	for (int i = 1; i < phone_book.size() - 1; i++) {
		// 접두어면 바로 false 리턴
		if (isPrefix(phone_book[i - 1], phone_book[i]))
			return false;
		if (isPrefix(phone_book[i], phone_book[i + 1]))
			return false;
	}

	// 모두 접두어가 아니면 true 리턴
	return true;
}
