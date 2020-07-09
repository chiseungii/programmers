def solution(s):
    if len(s) != 4 and len(s) != 6:
        return False
    else:
        only_digit = True
        for i in range(len(s)):
            if not s[i].isdigit():
                only_digit = False
                
        return only_digit
