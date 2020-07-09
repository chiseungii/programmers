def solution(s, n):
    result = ""
    for i in range(len(s)):
        if s[i].isalpha():
            if s[i].isupper():
                tmp = ord(s[i]) - ord('A')
                tmp += n
                tmp %= 26
                result += chr(tmp + ord('A'))
            else:
                tmp = ord(s[i]) - ord('a')
                tmp += n
                tmp %= 26
                result += chr(tmp + ord('a'))
        else:
            result += s[i]
            
    return result
