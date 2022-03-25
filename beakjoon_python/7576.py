# BFS 상하좌우

from collections import deque

N, M = input().split()
N, M = int(N), int(M)

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
graph = [list(map(int, input().split())) for _ in range(M)]

def bfs():
    q = deque([])
    zero_count = 0
    one_count = 0
    max_val = 0
    for i in range(M):
        for j in range(N):
            if graph[i][j] == 0:
                zero_count += 1
            elif graph[i][j] == 1:
                one_count += 1
                q.append([i, j, 0])
    if zero_count == 0:
        return 0
    elif one_count == 0:
        return -1
    
    while(len(q) != 0):
        y = q[0][0]
        x = q[0][1]
        c = q[0][2]
        q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny < 0 or ny >= M:
                continue
            if nx < 0 or nx >= N:
                continue
            
            if graph[ny][nx] == 0:
                q.append([ny, nx, c+1])
                max_val = c+1
                graph[ny][nx] = 1
                zero_count -= 1
                
    if zero_count == 0:
        return max_val
    elif zero_count > 0:
        return -1
    
print(bfs())