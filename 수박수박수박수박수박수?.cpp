#include <iostream>
using namespace std;

string solution(int n) {
	string result = "";
	if (n % 2) {
		for (int i = 0; i < n / 2; i++)
			result += "수박";
		result += "수";
	}
	else {
		for (int i = 0; i < n / 2; i++)
			result += "수박";
	}

	return result;
}
