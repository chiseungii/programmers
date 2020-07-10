def solution(N, stages):
    players_through_stage = [0] * (N + 2)
    players_on_stage = [0] * (N + 2)
    for i in range(len(stages)):
        players_on_stage[stages[i]] += 1
        for j in range(1, stages[i] + 1):
            players_through_stage[j] += 1
            
    rate = []
    for i in range(1, N + 1):
        if players_through_stage[i] == 0: rate_fail = 0
        else: rate_fail = players_on_stage[i] / players_through_stage[i]
        rate.append([i, rate_fail])
    rate.sort(key=lambda x: (-x[1], x[0]))
    
    answer = []
    for i in range(len(rate)):
        answer.append(rate[i][0])
        
    return answer
