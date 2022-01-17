from collections import deque
N, D = input().split()
N, D = int(N), int(D)

road_list = [[] for _ in range(10001)]
distance = [i for i in range(10001)]
for i in range(N):
    temp_list = input().split()
    temp_list = list(map(int, temp_list))
    road_list[temp_list[0]].append([temp_list[2], temp_list[1]])

for i in range(D+1):
    if i != 0:
        distance[i] = min(distance[i], distance[i-1]+1)
    for w, e in road_list[i]:
        if e<=D and distance[e] > w + distance[i]:
            distance[e] = w + distance[i]

print(distance[D])
