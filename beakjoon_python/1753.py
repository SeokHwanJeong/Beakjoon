V, E = input().split()
V, E = int(V), int(E)
K = int(input()) - 1

mapp = []

for i in range(V):
    mapp.append(list())

for _ in range(E):
    uvw = input().split()
    uvw = list(map(int, uvw))
    uvw[0] = uvw[0] - 1
    uvw[1] = uvw[1] - 1
    mapp[uvw[0]].append([uvw[1], uvw[2]])

ans = list(99999 for i in range(V))
is_visit = list(1 for i in range(V))

for i in mapp[K]:
    ans[i[0]] = i[1]

is_visit[K] = 0
for i in range(V-2):
    min_val = 99999
    min_idx = 0
    for j in range(V):
        if ans[j] < min_val and is_visit[j]:
            min_val = ans[j]
            min_idx = j
    is_visit[min_idx] = 0
    for j in mapp[min_idx]:
        if is_visit[j[0]]:
            if ans[min_idx] + j[1] < ans[j[0]]:
                ans[j[0]] = ans[min_idx] + j[1]


for i in range(V):
    if i == K:
        print(0)
    elif ans[i] == 99999:
        print("INF")
    else:
        print(ans[i])
