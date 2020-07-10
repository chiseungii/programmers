LEFT = 0; RIGHT = 1; DONT_KNOW = 2

def dis(hand, num):
    result = abs(hand // 10 - num // 10)
    result += abs(hand % 10 - num % 10)

    return result

def solution(numbers, hand):
    loc = [42, 11, 12, 13, 21, 22, 23, 31, 32, 33]
    hands = [2, 0, 2, 1, 0, 2, 1, 0, 2, 1]
    left = 41; right = 43
    
    answer = ""
    for number in numbers:
        if hands[number] == LEFT:
            answer += "L"
            left = loc[number]
        elif hands[number] == RIGHT:
            answer += "R"
            right = loc[number]
        else:
            left_dis = dis(left, loc[number])
            right_dis = dis(right, loc[number])
            
            if left_dis == right_dis:
                if hand == "right":
                    answer += "R"
                    right = loc[number]
                else:
                    answer += "L"
                    left = loc[number]
            elif left_dis < right_dis:
                answer += "L"
                left = loc[number]
            else:
                answer += "R"
                right = loc[number]
                
    return answer
