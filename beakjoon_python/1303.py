import sys
from collections import deque
sys.setrecursionlimit(10**6)

C, R = input().split()
R, C = int(R), int(C)

B = 0
W = 0
maps = []
maps_check = []
move = [[1, 0],[-1, 0],[0, 1],[0, -1]]
for i in range(R):
    maps.append(list(map(str,input())))
    maps_check.append(list(1 for j in range(C)))

def bfs(y, x, k):
    maps_check[y][x] = 0;
    queue = deque()
    queue.append([y, x])
    while len(queue) != 0:
        a = queue.popleft()
        for i in range(4):
            yn, xn = a[0] + move[i][0], a[1] + move[i][1]

            if yn < 0 or yn >=R or xn < 0 or xn >=C:
                continue

            if maps[y][x] == maps[yn][xn]:
                if maps_check[yn][xn]:
                    maps_check[yn][xn] = 0;
                    queue.append([yn, xn])
                    k=k+1;
    return k
        
def dfs(y, x, k):
    maps_check[y][x] = 0;

    for i in range(4):
        yn, xn = y + move[i][0], x + move[i][1]

        if yn < 0 or yn >=R or xn < 0 or xn >=C:
            continue

        if maps[y][x] == maps[yn][xn]:
            if maps_check[yn][xn]:
                k = dfs(yn, xn, k+1)
    return k

for i in range(R):
    for j in range(C):
        if maps_check[i][j]:
            temp=bfs(i, j, 1)
            if maps[i][j]=='B':
                B = B + temp*temp
            else:
                W = W + temp*temp

print(W, B);

