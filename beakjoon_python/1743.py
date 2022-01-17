import sys
sys.setrecursionlimit(10**6)

NMK = input().split()
NMK = list(map(int, NMK))

road = []
is_visit = []
add = [[1, 0],[-1, 0],[0, 1],[0, -1]]
max_value = 0

for i in range(NMK[0]):
    road.append(list(0 for j in range(NMK[1])))
    is_visit.append(list(1 for j in range(NMK[1])))

for i in range(NMK[2]):
    x, y = input().split()
    x, y = int(x)-1, int(y)-1
    road[x][y] = 1

def dfs(y, x, sum):
    is_visit[y][x] = 0
    for i in add:
        next_y, next_x = y+i[0], x+i[1]
        if next_y < 0 or next_y >= NMK[0]:
            continue
        if next_x < 0 or next_x >= NMK[1]:
            continue
        if road[next_y][next_x] and is_visit[next_y][next_x]:
            sum = dfs(next_y, next_x, sum)

    return sum+1

for i in range(NMK[0]):
    for j in range(NMK[1]):
        if is_visit[i][j] and road[i][j]:
            temp = dfs(i, j, 0)
            if max_value < temp:
                max_value = temp

print(max_value)

