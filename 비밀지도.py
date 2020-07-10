def decoding(size, n):
    two = 2 ** (size-1)
    result = ""
    for i in range(size):
        if n >= two:
            result += '#'
            n -= two
        else: result += ' '
        
        two //= 2
        
    return result

def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        s1 = decoding(n, arr1[i])
        s2 = decoding(n, arr2[i])
        
        s3 = ""
        for j in range(n):
            if s1[j] == '#' or s2[j] == '#':
                s3 += '#'
            else: s3 += ' '
            
        answer.append(s3)
        
    return answer
