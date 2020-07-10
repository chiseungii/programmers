NON_SCORE = 999999999

def solution(dartResult):
    answer = 0
    index = 0; before_score = NON_SCORE
    for i in range(3):
        score = int(dartResult[index]); index += 1
        if dartResult[index] == '0':
            score = 10
            index += 1
            
        bonus = dartResult[index]; index += 1
        if bonus == 'D': score *= score
        elif bonus == 'T': score = score ** 3
        
        if index >= len(dartResult): pass
        elif dartResult[index] == '#':
            score = -score
            index += 1
        elif dartResult[index] == '*':
            if before_score == NON_SCORE: score *= 2
            else:
                score *= 2
                answer += before_score
            index += 1
            
        answer += score
        before_score = score
        
    return answer
