def solution(a, b):
    days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30]
    
    day = 0
    for i in range(1, a):
        day += days[i - 1]
    day += b - 1
    
    week = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]
    return week[day % 7]
