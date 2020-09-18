#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	string s1 = to_string(a);
	string s2 = to_string(b);

	string r1 = s1 + s2;
	string r2 = s2 + s1;

	return r1 > r2;
}

string solution(vector<int> numbers) {
	sort(numbers.begin(), numbers.end(), compare);

	string result = "";
	for (int i = 0; i < numbers.size(); i++)
		result += to_string(numbers[i]);
    if (result[0] == '0') result = "0";

	return result;
}
