def solution(arr):
    min_arr = min(arr)
    
    answer = []
    for a in arr:
        if a != min_arr:
            answer.append(a)
            
    if len(answer) == 0: answer.append(-1)
    return answer
