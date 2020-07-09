def solution(arr, divisor):
    result = []
    for a in arr:
        if a % divisor == 0:
            result.append(a)
            
    if len(result) == 0: result.append(-1)
    return sorted(result)
