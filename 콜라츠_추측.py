def solution(num):
    cnt = 0
    while num != 1:
        if cnt == 500:
            cnt = -1
            break
        cnt += 1
        
        if num % 2:
            num *= 3
            num += 1
        else:
            num //= 2
            
    return cnt
