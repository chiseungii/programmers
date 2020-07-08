NO_CLOTHES = 0; HAVE_CLOTHES = 1; MORE_CLOTHES = 2

def solution(n, lost, reserve):
    students = [HAVE_CLOTHES] * (n + 2)
    for r in reserve:
        students[r] += 1
    for l in lost:
        students[l] -= 1

    for i in range(1, n + 1):
        if students[i] == NO_CLOTHES:
            if students[i - 1] == MORE_CLOTHES and students[i + 1] <= 1:
                students[i - 1] = HAVE_CLOTHES
                students[i] = HAVE_CLOTHES
            elif students[i - 1] <= 1 and students[i + 1] == MORE_CLOTHES:
                students[i + 1] = HAVE_CLOTHES
                students[i] = HAVE_CLOTHES

    for i in range(1, n + 1):
        if students[i] == NO_CLOTHES:
            if students[i - 1] == MORE_CLOTHES and students[i + 1] == MORE_CLOTHES:
                students[i] += 1

    cnt = 0
    for i in range(1, n + 1):
        if students[i]:
            cnt += 1
            
    return cnt
