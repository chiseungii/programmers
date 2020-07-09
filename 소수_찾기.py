def solution(n):
    prime = [1] * (n + 1)
    
    for i in range(2, n + 1):
        if prime[i]:
            for j in range(i * 2, n + 1, i):
                prime[j] = 0
                
    return prime[2:].count(1)
