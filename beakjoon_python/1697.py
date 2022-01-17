from collections import deque

ti = input().split()
ti = list(map(int, ti))
is_visit = list(1 for i in range(100001))

is_visit[ti[0]] = 0

def bfs(N, D):
    queue = deque()
    queue.append([N, 0, 0])

    while len(queue) != 0:
        now = queue.popleft()
        if now[0] == D:
            return now[1]
        if now[2] == 1:
            if now[0]-1 >= 0:
                if is_visit[now[0]-1]:
                    queue.append([now[0]-1, now[1]+1, 1])
                    is_visit[now[0]-1] = 0
            if now[0]*2 < 100001:
                if is_visit[now[0]*2]:
                    queue.append([now[0]*2, now[1]+1, 3])
                    is_visit[now[0]*2] = 0
        elif now[2] == 2:
            if now[0]+1 < 100001:
                if is_visit[now[0]+1]:
                    queue.append([now[0]+1, now[1]+1, 2])
                    is_visit[now[0]+1] = 0
            if now[0]*2 < 100001:
                if is_visit[now[0]*2]:
                    queue.append([now[0]*2, now[1]+1, 3])
                    is_visit[now[0]*2] = 0
        else:
            if now[0]-1 >= 0:
                if is_visit[now[0]-1]:
                    queue.append([now[0]-1, now[1]+1, 1])
                    is_visit[now[0]-1] = 0
            if now[0]+1 < 100001:
                if is_visit[now[0]+1]:
                    queue.append([now[0]+1, now[1]+1, 2])
                    is_visit[now[0]+1] = 0
            if now[0]*2 < 100001:
                if is_visit[now[0]*2]:
                    queue.append([now[0]*2, now[1]+1, 3])
                    is_visit[now[0]*2] = 0

ans = bfs(ti[0], ti[1])

print(ans)

