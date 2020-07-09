#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> result = { arr[0] };
	for (int i = 1; i < arr.size(); i++)
		if (result.back() != arr[i])
			result.push_back(arr[i]);

	return result;
}
