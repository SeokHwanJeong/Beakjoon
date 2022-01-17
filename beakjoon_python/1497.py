from itertools import combinations

N, M = input().split()
N, M = int(N), int(M)

g_s = []
for i in range(N):
    guitar, can_song = input().split()
    can_song = can_song.replace('Y', '1')
    can_song = can_song.replace('N', '0')
    can_song = int(can_song, 2)
    g_s.append(can_song)

ans = 0
for i in g_s:
    ans = ans|i

if ans == 0:
    print(-1)
else:
    flag = 0
    for i in range(N+1):
        for j in combinations(g_s, i):
            t = 0
            for k in j:
                t = t|k
            if t==ans:
                print(i)
                flag = 1
                break
        if flag:
            break