#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> result;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> sub;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
			sub.push_back(array[j]);

		sort(sub.begin(), sub.end());
		result.push_back(sub[commands[i][2] - 1]);
	}

	return result;
}
