def solution(arr):
    result = [arr[0]]
    for i in range(1, len(arr)):
        if result[-1] != arr[i]:
            result.append(arr[i])
            
    return result
