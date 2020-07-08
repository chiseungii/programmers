#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
	int num_answer[3] = { 5, 8, 10 };
	int students[3][10] = { {1, 2, 3, 4, 5, 0, 0, 0, 0, 0}, {2, 1, 2, 3, 2, 4, 2, 5, 0, 0}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
	int correct[3] = { 0, 0, 0 };

	int index = 0;
	for (int i = 0; i < answers.size(); i++, index++) {
		for (int j = 0; j < 3; j++)
			if (answers[i] == students[j][index % num_answer[j]])
				correct[j]++;
	}

	int max_correct = correct[0];
	if (correct[1] > max_correct) max_correct = correct[1];
	if (correct[2] > max_correct) max_correct = correct[2];

	vector<int> result;
	for (int i = 0; i < 3; i++)
		if (correct[i] == max_correct)
			result.push_back(i + 1);

	return result;
}
