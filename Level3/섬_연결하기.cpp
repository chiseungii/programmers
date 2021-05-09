#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

int roots[100];	// 부모 노드 저장

bool compare(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

//int findRoot(int n) {
//	while (parents[n] != n) {
//		n = parents[n];
//	}
//
//	return n;
//}

int solution(int n, vector<vector<int>> costs) {
	// init roots
	for (int i = 0; i < n; i++)
		roots[i] = i;

	// 비용이 작은 순으로 정렬
	sort(costs.begin(), costs.end(), compare);

	int sum_cost = 0;	// 총 비용

	for (vector<int> cost : costs) {
		int n1 = cost[0];
		int n2 = cost[1];

		// n1 < n2 로 맞추기
		if (n1 > n2) {
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
		}

		//// 두 노드의 루트 노드가 다르면 추가
		//if (findRoot(n1) != findRoot(n2)) {
		//	if (parents[n1] == n1) parents[n1] = n2;
		//	else parents[n2] = n1;
		//	sum_cost += cost[2];
		//}

		// 두 노드의 루트가 다르면 추가
		if (roots[n1] != roots[n2]) {
			sum_cost += cost[2];

			int tmp = roots[n2];
			for (int i = 0; i < n; i++) {
				if (roots[i] == tmp)
					roots[i] = roots[n1];
			}
		}
	}

	return sum_cost;
}
