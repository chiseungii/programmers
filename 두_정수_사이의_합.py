def solution(a, b):
    start = min(a, b)
    end = max(a, b)
    
    sum = 0
    for i in range(start, end + 1):
        sum += i
        
    return sum
