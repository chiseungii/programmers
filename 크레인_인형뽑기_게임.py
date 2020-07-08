def solution(board, moves):
    N = len(board)
    basket = []

    cnt = 0
    for move in moves:
        for i in range(N):
            if board[i][move - 1]:
                basket.append(board[i][move - 1])
                board[i][move - 1] = 0
                break

        if len(basket) >= 2 and basket[-1] == basket[-2]:
            cnt += 1
            basket.pop()
            basket.pop()

    return cnt * 2
