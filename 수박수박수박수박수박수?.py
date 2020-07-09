def solution(n):
    result = ""
    if n % 2:
        for i in range(n // 2):
            result += "수박"
        result += "수"
    else:
        for i in range(n // 2):
            result += "수박"
            
    return result
