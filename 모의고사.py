def solution(answers):
    num_answer = [5, 8, 10]
    students = [
        [1, 2, 3, 4, 5, 0, 0, 0, 0, 0],
        [2, 1, 2, 3, 2, 4, 2, 5, 0, 0],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]
    correct = [0, 0, 0]
    
    index = 0
    for i in range(len(answers)):
        for j in range(3):
            if answers[i] == students[j][index % num_answer[j]]:
                correct[j] += 1
        index += 1
        
    max_correct = max(correct)
    result = []
    for i in range(3):
        if correct[i] == max_correct:
            result.append(i + 1)
            
    return result
