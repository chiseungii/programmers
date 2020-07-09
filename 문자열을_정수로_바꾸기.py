def solution(s):
    plus = True
    if s[0] == '-':
        s = s[1:]
        plus = False
    elif s[0] == '+':
        s = s[1:]
        
    result = 0
    for i in range(len(s)):
        result = result * 10 + int(s[i])
    if not plus: result = -result
    
    return result
