#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> heap;	// 오름차순 힙

	for (string op : operations) {
		if (op[0] == 'I') {
			int num = stoi(op.substr(2));
			heap.push_back(num);
			sort(heap.begin(), heap.end());
		}
		else if (op[0] == 'D') {
			// 힙이 비어있을 경우
			if (heap.empty()) continue;
			else if (op[2] == '1')
				heap.pop_back();
			else heap.erase(heap.begin());
		}
	}

	vector<int> result;

	if (heap.empty()) {
		result.push_back(0);
		result.push_back(0);
	}
	else {
		result.push_back(heap.back());
		result.push_back(heap.front());
	}

	return result;
}
