def solution(n):
    tmp = []
    while n > 0:
        tmp.append(n % 10)
        n //= 10
    tmp.sort(reverse=True)
    
    answer = 0
    for t in tmp:
        answer = answer * 10 + t
        
    return answer
