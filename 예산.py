def solution(d, budget):
    d.sort()
    cnt = 0
    for di in d:
        if budget >= di:
            budget -= di
            cnt += 1
        else: break
        
    return cnt
