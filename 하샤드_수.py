def solution(x):
    sum = 0; tmp = x
    while tmp > 0:
        sum += tmp % 10
        tmp //= 10
        
    if x % sum: return False
    else: return True
