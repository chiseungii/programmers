#include <iostream>
#include <vector>
using namespace std;

string itos(int n) {
	if (n < 10) {
		char tmp = n + '0';
		string result = "";
		result += tmp;

		return result;
	}
	else {
		string result = "";
		while (n > 0) {
			char tmp = n % 10 + '0';
			result = tmp + result;
			n /= 10;
		}

		return result;
	}
}

string solution(vector<string> seoul) {
	int index;
	for (int i = 0; i < seoul.size(); i++) {
		if (seoul[i] == "Kim") {
			index = i;
			break;
		}
	}

	string result = "김서방은 ";
	result += itos(index);
	result += "에 있다";
	
	return result;
}
