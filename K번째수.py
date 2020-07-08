def solution(array, commands):
    result = []
    for command in commands:
        sub = []
        for j in range(command[0] - 1, command[1]):
            sub.append(array[j])

        sub = sorted(sub)
        result.append(sub[command[2] - 1])

    return result
