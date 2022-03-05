// https://programmers.co.kr/learn/courses/30/lessons/86971
// bfs 이용

#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<bool>> graph) {
	int cnt = 0;
	vector<bool> visit;
	for (int i = 0; i <= n; i++) visit.push_back(false);
	visit[1] = true;

	queue<int> q; q.push(1);

	while (q.size()) {
		int tmp = q.front();
		q.pop();
		cnt++;

		for (int i = 1; i <= n; i++) {
			if (graph[tmp][i] && !visit[i]) {
				visit[i] = true;
				q.push(i);
			}
		}
	}

	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	vector<vector<bool>> graph;
	for (int i = 0; i <= n; i++) {
		vector<bool> g;
		for (int j = 0; j <= n; j++) g.push_back(false);
		graph.push_back(g);
	}

	// 그래프 잇기
	for (vector<int> wire : wires) {
		graph[wire[0]][wire[1]] = true;
		graph[wire[1]][wire[0]] = true;
	}

	// 하나씩 잘라서 비교
	int min_res = 1000000;	// 송전탑 개수 차이 최소값

	for (vector<int> wire : wires) {
		// 연결 끊기
		graph[wire[0]][wire[1]] = false;
		graph[wire[1]][wire[0]] = false;

		int tmp1 = bfs(n, graph);
		int tmp2 = n - tmp1;
		if (abs(tmp1 - tmp2) < min_res) min_res = abs(tmp1 - tmp2);

		// 다시 잇기
		graph[wire[0]][wire[1]] = true;
		graph[wire[1]][wire[0]] = true;
	}

	return min_res;
}
