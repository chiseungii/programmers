#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int N = board.size();
	vector<int> basket;

	int cnt = 0;
	for (int i = 0; i < moves.size(); i++) {
		int m = moves[i] - 1;
		for (int j = 0; j < N; j++) {
			if (board[j][m]) {
				basket.push_back(board[j][m]);
				board[j][m] = 0;
				break;
			}
		}

		if (basket[basket.size() - 1] == basket[basket.size() - 2]) {
			cnt++;
			basket.pop_back();
			basket.pop_back();
		}
	}

	return cnt * 2;
}
