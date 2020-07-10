from math import sqrt

def solution(n):
    tmp = int(sqrt(n))
    
    if tmp**2 == n:
        return (tmp + 1)**2
    else: return -1
