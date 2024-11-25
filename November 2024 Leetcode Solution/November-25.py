from collections import deque

class Solution:
    def slidingPuzzle(self, board: list[list[int]]) -> int:
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        goal = "123450"
        start = ''.join(str(board[i][j]) for i in range(2) for j in range(3))

        if start == goal:
            return 0

        queue = deque([(start, 0)])
        seen = {start}

        while queue:
            state, steps = queue.popleft()
            zero_index = state.index('0')
            x, y = divmod(zero_index, 3)

            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < 2 and 0 <= ny < 3:
                    next_state = list(state)
                    next_state[zero_index], next_state[nx * 3 + ny] = next_state[nx * 3 + ny], next_state[zero_index]
                    next_state = ''.join(next_state)
                    if next_state == goal:
                        return steps + 1
                    if next_state not in seen:
                        queue.append((next_state, steps + 1))
                        seen.add(next_state)
        return -1
