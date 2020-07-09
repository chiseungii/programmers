def solution(s):
    tmp = [s[i] for i in range(len(s))]
    tmp = sorted(tmp)
    
    result = ""
    for i in range(len(tmp) - 1, -1, -1):
        result += tmp[i]
        
    return result
