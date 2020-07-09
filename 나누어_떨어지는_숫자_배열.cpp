#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> result;
	for (int i = 0; i < arr.size(); i++)
		if (arr[i] % divisor == 0)
			result.push_back(arr[i]);

	if (result.size() == 0) result.push_back(-1);
	sort(result.begin(), result.end());
	return result;
}
