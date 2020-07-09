def solution(s):
    result = ""
    index = 0
    for i in range(len(s)):
        if s[i] == ' ':
            index = 0
            result += ' '
        else:
            if index % 2:
                result += s[i].lower()
            else:
                result += s[i].upper()
            index += 1
            
    return result
