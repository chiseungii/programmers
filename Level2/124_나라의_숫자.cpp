#include <iostream>
#include <string>
using namespace std;

string solution(int n) {
	string result = "";
	while (n > 0) {
		int tmp = n % 3;
		n /= 3;

		if (tmp == 0) { tmp = 4; n--; }
		result = to_string(tmp) + result;
	}

	return result;
}
