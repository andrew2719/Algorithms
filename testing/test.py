from collections import deque

def brute_force_bfs(grid):
    rows, cols = len(grid), len(grid[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right
    min_guards_matrix = [[float('inf')] * cols for _ in range(rows)]

    def bfs(start_r, start_c):
        queue = deque([(start_r, start_c, 0)])  # (row, col, guards_count)
        visited = [[False] * cols for _ in range(rows)]
        visited[start_r][start_c] = True
        min_guards = float('inf')
        
        while queue:
            r, c, guards = queue.popleft()

            # If on a boundary, update the minimum guards encountered
            if r == 0 or r == rows-1 or c == 0 or c == cols-1:
                min_guards = min(min_guards, guards)
                continue

            # Explore all possible directions
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and not visited[nr][nc]:
                    visited[nr][nc] = True
                    if grid[nr][nc] == 1:
                        queue.append((nr, nc, guards + 1))
                    else:
                        queue.append((nr, nc, guards))

        return min_guards

    max_min_guards = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 0:
                # Perform BFS for each prisoner and update the maximum of minimum guards encountered
                max_min_guards = max(max_min_guards, bfs(r, c))

    return max_min_guards

for _ in range(int(input())):
    n,m = [int(x) for x in input().split()]
    # matrix = []
    # for i in range(n):
    #     s = input()
    #     matrix.append(s)
    # print(escape_times(matrix))
    grid = []
    for j in range(n):
        grid.append([int(i) for i in list(input())])
    print(brute_force_bfs(grid))
        
    
# # Input data
# n, m = 5, 5
# matrix = [
#     "11111",
#     "10101",
#     "11011",
#     "10101",
#     "11111"
# ]

# Calculate the maximum escape time for the prisoners
