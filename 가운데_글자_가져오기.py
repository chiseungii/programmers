def solution(s):
    l = len(s)
    if l % 2:
        return s[l//2:l//2+1]
    else:
        return s[(l-1)//2:(l-1)//2+2]
