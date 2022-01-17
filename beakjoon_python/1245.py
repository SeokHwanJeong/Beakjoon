from typing import DefaultDict

R, C = input().split()
R, C = int(R), int(C)

maps = []
map_check = []
flag = 1;
dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, 1, -1, -1]
ans = 0;
for i in range(R):
    temp = input().split()
    temp = list(map(int, temp))
    maps.append(temp)
    map_check.append(list(1 for j in range(C)))

def check(i, j):
    global flag
    #map_check[i][j] = 0;
    for k in range(8):
        x = i + dx[k]
        y = j + dy[k]
        
        if x<0 or x>=R or y<0 or y>=C:
            continue;

        if maps[x][y] > maps[i][j]:
            flag = 0;
        if map_check[x][y] == 0 or maps[x][y] != maps[i][j]:
            continue;
        map_check[x][y] = 0;
        check(x, y);
    return ;

for i in range(R):
    for j in range(C):
        if map_check[i][j] == 1:
            flag = 1;
            check(i, j);
            ans += flag
print(ans)

