#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string decoding(int size, int n) {
	int two = pow(2, size - 1);
	string result = "";
	for (int i = 0; i < size; i++) {
		if (n >= two) {
			result += '#';
			n -= two;
		}
		else result += ' ';

		two /= 2;
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		string s1 = decoding(n, arr1[i]);
		string s2 = decoding(n, arr2[i]);

		string s3 = "";
		for (int j = 0; j < n; j++) {
			if (s1[j] == '#' || s2[j] == '#')
				s3 += '#';
			else s3 += ' ';
		}

		answer.push_back(s3);
	}

	return answer;
}
