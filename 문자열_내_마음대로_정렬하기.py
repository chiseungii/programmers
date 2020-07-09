def solution(strings, n):
    strings = sorted(strings)
    strings = sorted(strings, key=lambda x: x[n])
    return strings
